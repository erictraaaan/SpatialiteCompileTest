//
//  ViewController.m
//  dec5objc
//
//  Created by Eric Tran on 2017-12-05.
//  Copyright © 2017 Eric Tran. All rights reserved.
//

#import "ViewController.h"

#import <SpatialDatabase.h> //MUST INCLUDE THIS TO WORK!!!!!!!
/*
 uses SpatialDBKit straight from cocoapods.  no modifications.
 follows the steps on the github and everything works fine.
 additional steps:
 1) replace line 87 of spatialite.c with import "spatialite/spatialite/spatialite.h"
 2) add the dummy.mm file
 3) replace contents of SpatialiteDatabase.m with this file:
 https://raw.githubusercontent.com/andreacremaschi/SpatialDBKit/master/SpatialDBKit/SpatialDatabase.m
 */

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSString *sqliteVersion = [SpatialDatabase sqliteLibVersion];
    NSLog(@"Hello from VC: sqlite version: %@", sqliteVersion);
    
    NSString *spatialiteVersion = [SpatialDatabase spatialiteLibVersion];
    NSLog(@"Hello from VC: spatialite version: %@", spatialiteVersion);
    
    // test spatialite AsText function -> ShapeKit object import
    SpatialDatabase *db = [SpatialDatabase databaseWithPath: [[NSBundle mainBundle] pathForResource:@"Assets/db3" ofType:@"sqlite"]] ;
    [db open];
    
    FMResultSet *rs = [db executeQuery:@"select AsText(geometry) AS text FROM Room1f WHERE rid = 4409"];
    //select geometry FROM Regions WHERE PK_UID = 106
    while ([rs next])
    {
        id object = [rs resultDictionary];
        
        NSLog(@"%@", object);
    }
    // Do any additional setup after loading the view, typically from a nib.
    
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
