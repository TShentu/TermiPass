// SPDX-License-Identifier: MIT
// Copyright © 2018-2023 WireGuard LLC. All Rights Reserved.

import Foundation
import os.log


public func tp_log(_ type: OSLogType, staticMessage msg: StaticString) {
//    os_log(msg, log: OSLog.default, type: type)
}

public func tp_log(_ type: OSLogType, message msg: String) {
//    os_log("%{public}s", log: OSLog.default, type: type, msg)
}
