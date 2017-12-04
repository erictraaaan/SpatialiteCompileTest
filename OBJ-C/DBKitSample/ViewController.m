//
//  ViewController.m
//  DBKitSample
//
//  Created by Eric Tran on 2017-11-20.
//  Copyright © 2017 Eric Tran. All rights reserved.
//

#import "ViewController.h"

#import <SpatialDBKit/SpatialDatabase.h>

//#import <SpatialDBKit/SpatialDatabase.h>

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
