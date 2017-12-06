//
//  ViewController.swift
//  dec5swift
//
//  Created by Eric Tran on 2017-12-05.
//  Copyright © 2017 Eric Tran. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    let myVar = SpatialDatabase.sqliteLibVersion()
    let test = SpatialDatabase.spatialiteLibVersion()

    override func viewDidLoad() {
        super.viewDidLoad()
        
        print ("Hello! current sqlite version: \(myVar)")
        print ("Hello! current spatialite version: \(test)")
        
        let db = SpatialDatabase(path: Bundle.main.path(forResource: "Assets/db3", ofType: "sqlite"))
        db?.open()
        
//        let myDB = SpatialDatabase(path: "Assets/db3.sqlite")
//        let myString = myDB?.databasePath()
//        myDB?.open()
//        myDB?.close()
//        let result: FMResultSet = myDB?.executeQuery(<#T##sql: String!##String!#>, withVAList: <#T##CVaListPointer#>)
        
        
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

