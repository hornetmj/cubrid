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
package com.cubrid.cubridmanager.ui.cubrid.table.action;

import java.util.List;

import org.eclipse.jface.dialogs.IDialogConstants;
import org.eclipse.jface.resource.ImageDescriptor;
import org.eclipse.jface.viewers.ISelectionProvider;
import org.eclipse.jface.viewers.TreeViewer;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.ui.PlatformUI;

import com.cubrid.cubridmanager.core.cubrid.database.model.DatabaseInfo;
import com.cubrid.cubridmanager.core.cubrid.table.task.GetTablesTask;
import com.cubrid.cubridmanager.core.cubrid.table.task.RenameTableOrViewTask;
import com.cubrid.cubridmanager.ui.cubrid.table.dialog.RenameTableDialog;
import com.cubrid.cubridmanager.ui.spi.ActionManager;
import com.cubrid.cubridmanager.ui.spi.CommonTool;
import com.cubrid.cubridmanager.ui.spi.action.SelectionAction;
import com.cubrid.cubridmanager.ui.spi.model.CubridDatabase;
import com.cubrid.cubridmanager.ui.spi.model.CubridNodeType;
import com.cubrid.cubridmanager.ui.spi.model.DefaultSchemaNode;
import com.cubrid.cubridmanager.ui.spi.progress.CommonTaskExec;
import com.cubrid.cubridmanager.ui.spi.progress.ExecTaskWithProgress;
import com.cubrid.cubridmanager.ui.spi.progress.TaskExecutor;

public class RenameTableAction extends
		SelectionAction {

	public static final String ID = RenameTableAction.class.getName();

	/**
	 * The constructor
	 * 
	 * @param shell
	 * @param text
	 * @param icon
	 */
	public RenameTableAction(Shell shell, String text, ImageDescriptor icon) {
		this(shell, null, text, icon);
	}

	/**
	 * The constructor
	 * 
	 * @param shell
	 * @param provider
	 * @param text
	 * @param icon
	 */
	public RenameTableAction(Shell shell, ISelectionProvider provider,
			String text, ImageDescriptor icon) {
		super(shell, null, text, icon);
		this.setId(ID);

	}

	/**
	 * 
	 * @see com.cubrid.cubridmanager.ui.spi.action.ISelectionAction#allowMultiSelections ()
	 */
	public boolean allowMultiSelections() {
		return false;
	}

	/**
	 * 
	 * @see com.cubrid.cubridmanager.ui.spi.action.ISelectionAction#isSupported(java
	 *      .lang.Object)
	 */
	public boolean isSupported(Object obj) {
		if (obj instanceof DefaultSchemaNode) {
			DefaultSchemaNode table = (DefaultSchemaNode) obj;
			CubridNodeType type = table.getType();
			switch (type) {
			case USER_TABLE:
				setText(com.cubrid.cubridmanager.ui.spi.Messages.tableRenameActionName);
				break;
			case USER_VIEW:
				setText(com.cubrid.cubridmanager.ui.spi.Messages.viewRenameActionName);
				break;
			default:
			}
			return true;
		}
		return false;
	}

	public void run() {

		Object[] obj = this.getSelectedObj();
		if (!isSupported(obj[0])) {
			setEnabled(false);
			return;
		}
		DefaultSchemaNode table = (DefaultSchemaNode) obj[0];
		boolean isTable = false;
		CubridNodeType type = table.getType();
		switch (type) {
		case USER_TABLE:
			isTable = true;
			break;
		case USER_VIEW:
			isTable = false;
			break;
		default:
		}

		ISelectionProvider provider = this.getSelectionProvider();
		final TreeViewer viewer = (TreeViewer) provider;

		String username = table.getDatabase().getUserName();
		if (username == null || username.length() <= 0) {
			return;
		}
		String tableName = table.getName();
		CubridDatabase db = table.getDatabase();
		DatabaseInfo dbInfo = db.getDatabaseInfo();
		GetTablesTask getTableTask = new GetTablesTask(dbInfo);
		List<String> tableList = getTableTask.getAllTableAndViews();

		RenameTableDialog dlg = new RenameTableDialog(
				PlatformUI.getWorkbench().getActiveWorkbenchWindow().getShell(),
				tableName, isTable, tableList);
		int ret = dlg.open();
		if (ret == IDialogConstants.OK_ID) {

			String newName = dlg.getNewSchemaName();

			RenameTableOrViewTask task = new RenameTableOrViewTask(dbInfo);

			task.setOldClassName(tableName);
			task.setNewClassName(newName);
			task.setTable(isTable);

			TaskExecutor taskExecutor = new CommonTaskExec();
			taskExecutor.addTask(task);
			new ExecTaskWithProgress(taskExecutor).exec();
			//			task.execute();
			if (task.isSuccess()) {
				CommonTool.refreshNavigatorTree(viewer, table.getParent());
				ActionManager.getInstance().fireSelectionChanged(getSelection());
			}
		}

	}
}
