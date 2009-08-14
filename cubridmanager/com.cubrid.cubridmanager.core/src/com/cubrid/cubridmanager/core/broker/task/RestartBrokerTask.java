/*
 * Copyright (C) 2009 Search Solution Corporation. All rights reserved by Search Solution. 
 *
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met: 
 *
 * - Redistributions of source code must retain the above copyright notice, 
 *   this list of conditions and the following disclaimer. 
 *
 * - Redistributions in binary form must reproduce the above copyright notice, 
 *   this list of conditions and the following disclaimer in the documentation 
 *   and/or other materials provided with the distribution. 
 *
 * - Neither the name of the <ORGANIZATION> nor the names of its contributors 
 *   may be used to endorse or promote products derived from this software without 
 *   specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
 * IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE. 
 *
 */
package com.cubrid.cubridmanager.core.broker.task;

import com.cubrid.cubridmanager.core.common.StringUtil;
import com.cubrid.cubridmanager.core.common.model.ServerInfo;
import com.cubrid.cubridmanager.core.common.socket.SocketTask;

/**
 * This task is responsible for executing the task of starting broker
 * environment
 * 
 * @author lizhiqiang
 * @version 1.0 - 2009-5-15 created by lizhiqiang
 */
public class RestartBrokerTask extends
		SocketTask {

	private static final String[] sendMSGItems = new String[] { "task",
			"token", "bname", "asnum" };

	/**
	 * The constructor
	 * 
	 * @param taskName
	 * @param serverInfo
	 */
	public RestartBrokerTask(ServerInfo serverInfo) {
		super("broker_restart", serverInfo, sendMSGItems);
	}

	/**
	 * Sets the bname
	 * 
	 * @param dbName
	 */
	public void setBname(String bname) {
		super.setMsgItem("bname", bname);
	}

	/**
	 * Sets the asnum
	 * 
	 * @param asnum
	 */
	public void setAsnum(String asnum) {
		super.setMsgItem("asnum", asnum);
	}

	/**
	 * Return note if exists
	 * 
	 * @return
	 */
	public String getNote() {
		return StringUtil.nvl(this.getResponse().getValue("note"));
	}
}
