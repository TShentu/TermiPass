//
//  StorageUseriOSPlugin.swift
//  App
//
//  Created by gjm on 2023/3/3.
//

import Foundation
import Capacitor
import VaultBaseFramework

@objc(StorageUseriOSPlugin)
public class StorageUseriOSPlugin: CAPPlugin {
    @objc func set(_ call: CAPPluginCall) {
        let key = call.getString("key") ?? ""
        let value = call.getAny("value") ?? {}
        print(value)
        print(type(of: value))
        UserStorage.setData(key: key, value: value)
        call.resolve()
    }
    
    @objc func get(_ call: CAPPluginCall) {
        let key = call.getString("key") ?? ""
        let value = UserStorage.getData(key: key)
        print(value)
        print(type(of: value))
        call.resolve([
            "value": value
        ])
    }
    
    @objc func delete(_ call: CAPPluginCall) {
        let key = call.getString("key") ?? ""
        UserStorage.removeData(key: key)
        call.resolve()
    }
    
    @objc func clear(_ call: CAPPluginCall) {
        UserStorage.clearData()
        call.resolve()
    }
}

