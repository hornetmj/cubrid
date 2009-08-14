/*
 * Copyright (C) 2009 Search Solution Corporation. All rights reserved by Search
 * Solution.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met: -
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer. - Redistributions in binary
 * form must reproduce the above copyright notice, this list of conditions and
 * the following disclaimer in the documentation and/or other materials provided
 * with the distribution. - Neither the name of the <ORGANIZATION> nor the names
 * of its contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * 
 */
package com.cubrid.cubridmanager.ui.cubrid.dbspace.editor;

import java.awt.Color;
import java.io.File;
import java.lang.reflect.InvocationTargetException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;
import org.eclipse.core.runtime.IProgressMonitor;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;
import org.eclipse.jface.dialogs.ProgressMonitorDialog;
import org.eclipse.jface.operation.IRunnableWithProgress;
import org.eclipse.jface.viewers.TableViewer;
import org.eclipse.jface.viewers.ViewerSorter;
import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.ScrolledComposite;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Control;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Table;
import org.eclipse.swt.widgets.TableColumn;
import org.eclipse.ui.IEditorInput;
import org.eclipse.ui.IEditorSite;
import org.eclipse.ui.PartInitException;
import org.eclipse.ui.PlatformUI;
import org.eclipse.ui.help.IWorkbenchHelpSystem;
import org.jfree.chart.ChartColor;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.labels.StandardPieToolTipGenerator;
import org.jfree.chart.plot.PieLabelLinkStyle;
import org.jfree.chart.plot.PiePlot3D;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.experimental.chart.swt.ChartComposite;
import org.jfree.util.Rotation;

import com.cubrid.cubridmanager.core.common.ITask;
import com.cubrid.cubridmanager.core.common.log.LogUtil;
import com.cubrid.cubridmanager.core.common.socket.SocketTask;
import com.cubrid.cubridmanager.core.common.task.CommonQueryTask;
import com.cubrid.cubridmanager.core.common.task.CommonSendMsg;
import com.cubrid.cubridmanager.core.cubrid.dbspace.model.DbSpaceInfo;
import com.cubrid.cubridmanager.core.cubrid.dbspace.model.DbSpaceInfoList;
import com.cubrid.cubridmanager.help.CubridManagerHelpContextIDs;
import com.cubrid.cubridmanager.ui.cubrid.dbspace.Messages;
import com.cubrid.cubridmanager.ui.spi.CommonTool;
import com.cubrid.cubridmanager.ui.spi.CubridEditorPart;
import com.cubrid.cubridmanager.ui.spi.SWTResourceManager;
import com.cubrid.cubridmanager.ui.spi.TableContentProvider;
import com.cubrid.cubridmanager.ui.spi.TableLabelProvider;
import com.cubrid.cubridmanager.ui.spi.TableViewerSorter;
import com.cubrid.cubridmanager.ui.spi.event.CubridNodeChangedEvent;
import com.cubrid.cubridmanager.ui.spi.event.CubridNodeChangedEventType;
import com.cubrid.cubridmanager.ui.spi.model.CubridDatabase;
import com.cubrid.cubridmanager.ui.spi.model.CubridNodeType;
import com.cubrid.cubridmanager.ui.spi.model.DefaultSchemaNode;
import com.cubrid.cubridmanager.ui.spi.model.ICubridNode;
import com.cubrid.cubridmanager.ui.spi.model.ISchemaNode;
import com.cubrid.cubridmanager.ui.spi.progress.TaskJob;
import com.cubrid.cubridmanager.ui.spi.progress.TaskJobExecutor;

/**
 * 
 * This query editor part is responsible to show the status of database
 * 
 * @author robin 20090318
 */
public class VolumeInformationEditor extends
		CubridEditorPart {

	private static final Logger logger = LogUtil.getLogger(VolumeInformationEditor.class);
	public static final String ID = "com.cubrid.cubridmanager.ui.cubrid.dbspace.editor.VolumeInformationEditor";
	private CubridDatabase database = null;
	private DbSpaceInfo dbSpaceInfo = null;
	public static boolean isChanged = false;
	private boolean isRunning = false;

	private List<Map<String, String>> spInfoListData = new ArrayList<Map<String, String>>();
	private TableViewer spInfoTableViewer;
	private Table spInfoTable;
	private Label spaceNameLabel;
	private Composite parentComp;
	private Composite descGroup;
	private Composite composite;

	private ScrolledComposite sc = null;
	private final org.eclipse.swt.graphics.Color color;

	public VolumeInformationEditor() {
		color = SWTResourceManager.getColor(230, 230, 230);
	}

	@Override
	public void init(IEditorSite site, IEditorInput input) throws PartInitException {
		super.init(site, input);
		if (input instanceof DefaultSchemaNode) {
			ICubridNode node = (DefaultSchemaNode) input;
			if (node.getType() == CubridNodeType.GENERIC_VOLUME
					|| node.getType() == CubridNodeType.DATA_VOLUME
					|| node.getType() == CubridNodeType.INDEX_VOLUME
					|| node.getType() == CubridNodeType.TEMP_VOLUME
					|| node.getType() == CubridNodeType.ARCHIVE_LOG
					|| node.getType() == CubridNodeType.ACTIVE_LOG)
				dbSpaceInfo = (DbSpaceInfo) ((DefaultSchemaNode) node).getAdapter(DbSpaceInfo.class);
			database = ((DefaultSchemaNode) node).getDatabase();
		}
		setPartName(database.getName() + "-- Database space");
	}

	public void createPartControl(Composite parent) {
		sc = new ScrolledComposite(parent, SWT.H_SCROLL | SWT.V_SCROLL);
		FillLayout flayout = new FillLayout();
		sc.setLayout(flayout);

		IWorkbenchHelpSystem whs = PlatformUI.getWorkbench().getHelpSystem();
		whs.setHelp(sc, CubridManagerHelpContextIDs.volumeInformationEditor);

		parentComp = new Composite(sc, SWT.NONE);
		parentComp.setBackground(Display.getCurrent().getSystemColor(
				SWT.COLOR_WHITE));

		descGroup = new Composite(parentComp, SWT.NONE);
		composite = new Composite(parentComp, SWT.NONE);

		parentComp.setLayoutData(new GridData(GridData.FILL_BOTH));
		GridLayout layout = new GridLayout();
		layout.marginWidth = 10;
		layout.marginHeight = 10;
		parentComp.setLayout(layout);

		layout = new GridLayout();
		layout.marginWidth = 10;
		layout.marginHeight = 10;
		GridData gd_descGroup = new GridData(GridData.FILL_HORIZONTAL);
		descGroup.setLayoutData(gd_descGroup);
		descGroup.setLayout(layout);
		descGroup.setBackground(Display.getCurrent().getSystemColor(
				SWT.COLOR_WHITE));

		spaceNameLabel = new Label(descGroup, SWT.LEFT | SWT.WRAP);
		spaceNameLabel.setBackground(SWTResourceManager.getColor(255, 255, 255));
		spaceNameLabel.setFont(SWTResourceManager.getFont("", 20, SWT.BOLD));

		spaceNameLabel.setLayoutData(new org.eclipse.swt.layout.GridData(
				SWT.FILL, SWT.FILL, false, false));
		spaceNameLabel.setText("                                                            ");
		final String[] columnNameArr = new String[] { "col1", "col2" };
		spInfoTableViewer = createCommonTableViewer(descGroup, null,
				columnNameArr, CommonTool.createGridData(GridData.FILL_BOTH, 2,
						1, -1, -1));
		spInfoTableViewer.setInput(spInfoListData);
		spInfoTable = spInfoTableViewer.getTable();
		spInfoTable.setLinesVisible(true);
		spInfoTable.setHeaderVisible(false);

		layout = new GridLayout();
		layout.marginWidth = 10;
		layout.marginHeight = 10;

		gd_descGroup = new GridData();
		composite.setLayoutData(gd_descGroup);
		composite.setLayout(layout);
		composite.setBackground(Display.getCurrent().getSystemColor(
				SWT.COLOR_WHITE));
		loadData();
	}

	public void paintComp() {
		Control[] cs = composite.getChildren();
		for (Control c : cs)
			c.dispose();
		JFreeChart chart = createChart(createDataset());

		final ChartComposite frame = new ChartComposite(composite, SWT.NONE,

		chart, true);

		GridData gd_descGroup = new GridData(GridData.FILL_HORIZONTAL);
		gd_descGroup.widthHint = 600;
		gd_descGroup.heightHint = 400;
		frame.setLayoutData(gd_descGroup);

	}

	private DefaultPieDataset createDataset() {
		int freeSize = dbSpaceInfo.getFreepage();
		int totalSize = dbSpaceInfo.getTotalpage();

		DefaultPieDataset dataset = new DefaultPieDataset();
		dataset.setValue(
				Messages.chartMsgUsedSize,
				(totalSize - freeSize)
						* (database.getDatabaseInfo().getDbSpaceInfoList().getPagesize() / (1048576.0f)));
		dataset.setValue(
				Messages.chartMsgFreeSize,
				(freeSize)
						* (database.getDatabaseInfo().getDbSpaceInfoList().getPagesize() / (1048576.0f)));
		return dataset;

	}

	private void initial() {
		if (database == null || database.getDatabaseInfo() == null) {
			return;
		}

		if (database.getDatabaseInfo().getDbSpaceInfoList() == null) {
			return;
		}
		int totalSize = dbSpaceInfo.getTotalpage();
		int freeSize = dbSpaceInfo.getFreepage();

		spaceNameLabel.setText(dbSpaceInfo.getSpacename());

		while (spInfoListData.size() > 0)
			spInfoListData.remove(0);
		Map<String, String> map1 = new HashMap<String, String>();
		map1.put("0", Messages.lblSpaceLocation);
		map1.put("1", dbSpaceInfo.getLocation());
		spInfoListData.add(map1);

		Map<String, String> map2 = new HashMap<String, String>();
		map2.put("0", Messages.lblSpaceDate);
		map2.put("1", dbSpaceInfo.getDate());
		spInfoListData.add(map2);

		Map<String, String> map3 = new HashMap<String, String>();
		map3.put("0", Messages.lblSpaceType);
		map3.put(
				"1",
				dbSpaceInfo.getType()
						+ "                                                                               ");
		spInfoListData.add(map3);

		Map<String, String> map4 = new HashMap<String, String>();
		map4.put("0", Messages.lblFreeSize);
		map4.put(
				"1",
				CommonTool.formatNumber(
						freeSize
								* (database.getDatabaseInfo().getDbSpaceInfoList().getPagesize() / (1048576.0f)),
						"#,###.##")
						+ "M ("
						+ CommonTool.formatNumber(freeSize, "#,###")
						+ " pages)");
		spInfoListData.add(map4);

		Map<String, String> map5 = new HashMap<String, String>();
		map5.put("0", Messages.lblDatabaseTotalSize);
		map5.put(
				"1",
				CommonTool.formatNumber(
						totalSize
								* (database.getDatabaseInfo().getDbSpaceInfoList().getPagesize() / (1048576.0f)),
						"#,###.##")
						+ "M ("
						+ CommonTool.formatNumber(totalSize, "#,###")
						+ " pages)");
		spInfoListData.add(map5);

		Map<String, String> map6 = new HashMap<String, String>();
		map6.put("0", Messages.lblDatabasePaseSize);
		map6.put("1", CommonTool.formatNumber(
				database.getDatabaseInfo().getDbSpaceInfoList().getPagesize(),
				"#,###")
				+ " byte");
		spInfoListData.add(map6);

		spInfoTableViewer.refresh();
		for (int i = 0; i < spInfoTable.getColumnCount(); i++) {
			spInfoTable.getColumn(i).pack();
		}
		for (int i = 0; i < (spInfoTable.getItemCount() + 1) / 2; i++) {
			spInfoTable.getItem(i * 2).setBackground(color);
		}
	}

	@Override
	public void setFocus() {
	}

	@Override
	public void doSave(IProgressMonitor monitor) {
		firePropertyChange(PROP_DIRTY);
	}

	@Override
	public void doSaveAs() {
		// TODO Auto-generated method stub

	}

	@Override
	public boolean isDirty() {
		return false;
	}

	@Override
	public boolean isSaveAsAllowed() {
		return true;
	}

	public void setFile(File file) {
		// TODO Auto-generated method stub

	}

	public boolean loadData() {
		CommonQueryTask<DbSpaceInfoList> task = new CommonQueryTask<DbSpaceInfoList>(
				database.getServer().getServerInfo(),
				CommonSendMsg.commonDatabaseSendMsg, new DbSpaceInfoList());
		task.setDbName(database.getName());

		TaskJobExecutor taskJobExecutor = new TaskJobExecutor() {
			@SuppressWarnings("unchecked")
			@Override
			public IStatus exec(IProgressMonitor monitor) {

				if (monitor.isCanceled()) {
					return Status.CANCEL_STATUS;
				}

				for (ITask t : taskList) {
					t.execute();
					final String msg = t.getErrorMsg();

					if (monitor.isCanceled()) {
						return Status.CANCEL_STATUS;
					}
					if (msg != null && msg.length() > 0
							&& !monitor.isCanceled()) {
						Display.getDefault().syncExec(new Runnable() {
							public void run() {
								CommonTool.openErrorBox(msg);

							}
						});
						return Status.CANCEL_STATUS;
					} else {
						final DbSpaceInfoList model = ((CommonQueryTask<DbSpaceInfoList>) t).getResultModel();
						Display.getDefault().syncExec(new Runnable() {
							public void run() {
								database.getDatabaseInfo().setDbSpaceInfoList(
										model);
								initial();
								paintComp();
								sc.setContent(parentComp);
								sc.setExpandHorizontal(true);
								sc.setExpandVertical(true);
							}
						});
					}
					if (monitor.isCanceled()) {
						return Status.CANCEL_STATUS;
					}
				}
				return Status.OK_STATUS;
			}

		};
		taskJobExecutor.addTask(task);
		TaskJob job = new TaskJob("Database status Job", taskJobExecutor);
		job.setUser(false);
		job.schedule();

		// dbSpaceInfoList = task.getResultModel();
		return true;

	}

	public void execTask(final int buttonId, final SocketTask[] tasks,
			boolean cancelable) {
		final Shell shell = parentComp.getShell();
		final Display display = shell.getDisplay();
		isRunning = false;
		try {

			new ProgressMonitorDialog(shell).run(true, cancelable,
					new IRunnableWithProgress() {
						public void run(final IProgressMonitor monitor) throws InvocationTargetException,
								InterruptedException {
							monitor.beginTask(
									com.cubrid.cubridmanager.ui.spi.Messages.msgRunning,
									IProgressMonitor.UNKNOWN);

							if (monitor.isCanceled()) {
								return;
							}

							isRunning = true;
							Thread thread = new Thread() {
								public void run() {
									while (!monitor.isCanceled() && isRunning) {
										try {
											sleep(1);
										} catch (InterruptedException e) {
										}
									}
									if (monitor.isCanceled()) {
										for (SocketTask t : tasks) {
											if (t != null)
												t.cancel();
										}

									}
								}
							};
							thread.start();
							if (monitor.isCanceled()) {
								isRunning = false;
								return;
							}
							for (SocketTask task : tasks) {
								if (task != null) {
									task.execute();
									final String msg = task.getErrorMsg();
									if (monitor.isCanceled()) {
										isRunning = false;
										return;
									}
									if (msg != null && msg.length() > 0
											&& !monitor.isCanceled()) {
										display.syncExec(new Runnable() {
											public void run() {
												CommonTool.openErrorBox(shell,
														msg);
											}
										});
										isRunning = false;
										return;
									}
								}
								if (monitor.isCanceled()) {
									isRunning = false;
									return;
								}
							}
							if (monitor.isCanceled()) {
								isRunning = false;
								return;
							}

							isRunning = false;
							monitor.done();
						}
					});
		} catch (InvocationTargetException e) {
			logger.error(e.getMessage(), e);
		} catch (InterruptedException e) {
			logger.error(e.getMessage(), e);
		}
	}

	public void nodeChanged(CubridNodeChangedEvent e) {
		ICubridNode eventNode = e.getCubridNode();
		if (eventNode == null
				|| e.getType() != CubridNodeChangedEventType.CONTAINER_NODE_REFRESH) {
			return;
		}
		if (eventNode.getType() != CubridNodeType.DBSPACE_FOLDER) {
			return;
		}
		ISchemaNode eventSchemaNode = (ISchemaNode) eventNode;
		ISchemaNode schemaNode = (ISchemaNode) cubridNode;
		if (!eventSchemaNode.getDatabase().getId().equals(
				schemaNode.getDatabase().getId())) {
			return;
		}
		synchronized (cubridNode) {
			if (database.getDatabaseInfo().getDbSpaceInfoList() == null)
				loadData();
		}
	}

	/**
	 * 
	 * Create jfreechart
	 * 
	 * @param dataset
	 * @return
	 */
	private static JFreeChart createChart(DefaultPieDataset dataset) {

		JFreeChart chart = ChartFactory.createPieChart3D("", // chart

				// title

				dataset, // data

				true, // include legend

				true, false);

		PiePlot3D plot = (PiePlot3D) chart.getPlot();
		plot.setSectionOutlinesVisible(false);
		plot.setLabelFont(new java.awt.Font("SansSerif", java.awt.Font.PLAIN,
				12));
		plot.setDirection(Rotation.ANTICLOCKWISE);
		plot.setCircular(false);
		plot.setLabelLinkMargin(0.0);
		plot.setLabelGap(0.0);
		plot.setLabelLinkStyle(PieLabelLinkStyle.QUAD_CURVE);
		plot.setOutlinePaint(ChartColor.VERY_DARK_BLUE);

		plot.setLabelGenerator(null);
		plot.setLabelLinksVisible(false);
		plot.setLegendLabelGenerator(new org.jfree.chart.labels.StandardPieSectionLabelGenerator(
				"{0}:{1} Mbyte", new DecimalFormat("0.00"), new DecimalFormat(
						"0.00")));
		plot.setToolTipGenerator(new StandardPieToolTipGenerator(
				"{0}={1}Mbyte {2}", new DecimalFormat("0.00"),
				new DecimalFormat("0.00%")));
		// plot.setSectionPaint("", SWTResourceManager.getColor(230, 230, 230));
		Color[] colors = { new Color(235, 139, 82), new Color(119, 119, 253) };
		PieRenderer renderer = new PieRenderer(colors);
		renderer.setColor(plot, dataset);
		return chart;

	}

	/**
	 * 
	 * Create the common table viewer that can be sorted by TableViewerSorter
	 * object,this viewer's input object must be List<Map<String,Object>> and
	 * Map's key must be column index,Map's value of the column must be String.
	 * 
	 * @param parent
	 * @param sorter
	 * @param columnNameArr
	 * @param gridData
	 * @return
	 */
	public static TableViewer createCommonTableViewer(Composite parent,
			ViewerSorter sorter, final String[] columnNameArr, GridData gridData) {
		final TableViewer tableViewer = new TableViewer(parent, SWT.MULTI
				| SWT.BORDER | SWT.FULL_SELECTION);
		tableViewer.setContentProvider(new TableContentProvider());
		tableViewer.setLabelProvider(new TableLabelProvider());
		if (sorter != null)
			tableViewer.setSorter(sorter);

		tableViewer.getTable().setLinesVisible(true);
		tableViewer.getTable().setHeaderVisible(true);
		tableViewer.getTable().setLayoutData(gridData);

		for (int i = 0; i < columnNameArr.length; i++) {
			final TableColumn tblColumn = new TableColumn(
					tableViewer.getTable(), SWT.LEFT);
			tblColumn.setText(columnNameArr[i]);
			if (sorter != null) {
				tblColumn.addSelectionListener(new SelectionAdapter() {
					public void widgetSelected(SelectionEvent event) {
						TableColumn column = (TableColumn) event.widget;
						int j = 0;
						for (j = 0; j < columnNameArr.length; j++) {
							if (column.getText().equals(columnNameArr[j])) {
								break;
							}
						}
						TableViewerSorter sorter = ((TableViewerSorter) tableViewer.getSorter());
						if (sorter == null) {
							return;
						}
						sorter.doSort(j);
						tableViewer.getTable().setSortColumn(column);
						tableViewer.getTable().setSortDirection(
								sorter.isAsc() ? SWT.UP : SWT.DOWN);
						tableViewer.refresh();
						for (int k = 0; k < tableViewer.getTable().getColumnCount(); k++) {
							tableViewer.getTable().getColumn(k).pack();
						}
					}
				});
			}
			tblColumn.pack();
		}
		return tableViewer;
	}

	static class PieRenderer {
		/*
		 * Declaring an array of Color variables for storing a list of Colors
		 */
		private java.awt.Color[] color;

		/* Constructor to initialize PieRenderer class */
		public PieRenderer(java.awt.Color[] color) {
			this.color = color;
		}

		/**
		 * * Set Method to set colors for pie sections based on our choice*
		 * 
		 * @param plot PiePlot of PieChart*
		 * @param dataset PieChart DataSet
		 */
		@SuppressWarnings("unchecked")
		public void setColor(PiePlot3D plot, DefaultPieDataset dataset) {
			List keys = dataset.getKeys();
			int aInt;
			for (int i = 0; i < keys.size(); i++) {
				aInt = i % this.color.length;
				plot.setSectionPaint(dataset.getKey(i), this.color[aInt]);
			}
		}
	}
}
