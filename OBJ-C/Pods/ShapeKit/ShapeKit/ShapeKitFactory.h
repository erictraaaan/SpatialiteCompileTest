//
//  ShapeKitFactory.h
//  ShapeKit
//
//  Created by Andrea Cremaschi on 05/07/12.
//
// * This is free software; you can redistribute and/or modify it under
// the terms of the GNU Lesser General Public Licence as published
// by the Free Software Foundation. 
// See the COPYING file for more information.
//

#import <Foundation/Foundation.h>

@class ShapeKitGeometry;
@interface ShapeKitFactory : NSObject

//Singleton
+ (ShapeKitFactory *)defaultFactory;

// factory methods
- (ShapeKitGeometry *) geometryWithGEOSGeometry: (void *)geometry;
- (ShapeKitGeometry *) geometryWithWKB: (NSData *)wkbData;
- (ShapeKitGeometry *) geometryWithWKT: (NSString *)string;

@end
