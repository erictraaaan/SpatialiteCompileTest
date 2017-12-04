//
//  ShapeKitGeometry.h
//  ShapeKit
//
//  Created by Michael Weisman on 10-08-21.

// * This is free software; you can redistribute and/or modify it under
// the terms of the GNU Lesser General Public Licence as published
// by the Free Software Foundation. 
// See the COPYING file for more information.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#pragma mark - Abstract geometry

/** ShapeKitGeometry is an abstract class that holds generic information about your geometry.
 */
@interface ShapeKitGeometry : NSObject

/** @name Initialization */

/** An init method to be create the object out of a Well-Known-Binary representation of a geometry.
 */
- (id)initWithWKB:(const unsigned char *)wkb size:(size_t)wkb_size;

/** An init method to be create the object out of a Well-Known-Text representation of a geometry.
 */
- (id)initWithWKT:(NSString *)wkt;

/** An init method to be create the object out of an opaque GEOS data blob.
 */
- (id)initWithGeosGeometry:(void *)geom;

/** @name Properties */

/** Offers a Well Known Text representation of the geometry
 */
@property (readonly, copy) NSString *wktGeom;

/** A string representation of the geometry type.
 */
@property (readonly, copy) NSString *geomType;

/** A string representation of the SRID projection.
 */
@property (readonly, copy) NSString *projDefinition;

@property (readonly) void *handle;

/** This returns the number of coordinates in the geometry
 */
@property (readonly, nonatomic) unsigned int numberOfCoords;

/** This returns the index-th coordinate in the geometry's coordinates collection.
 */
- (CLLocationCoordinate2D)coordinateAtIndex:(NSInteger)index;

/** This can be used to reproject coordinates to a different SRID.
 */
- (void)reprojectTo:(NSString *)newProjectionDefinition;

@end


#pragma mark - Simple geometry objects

/** ShapeKitPoint offers a basic implementation of Point objects.
 */
@interface ShapeKitPoint : ShapeKitGeometry
@property (readonly) CLLocationCoordinate2D coordinate;
- (id)initWithCoordinate:(CLLocationCoordinate2D)coordinate;
@end

/** ShapeKitPolyline offers a basic implementation of Linestring objects.
 */
@interface ShapeKitPolyline : ShapeKitGeometry
-(id)initWithCoordinates:(CLLocationCoordinate2D[])coordinates count:(unsigned int)count;
@end

/** ShapeKitPolygon offers a basic implementation of Polygon objects.
 */
@interface ShapeKitPolygon : ShapeKitGeometry
- (id)initWithCoordinates:(CLLocationCoordinate2D[])coordinates count:(unsigned int)count;
@property (readonly) NSArray *interiors;
@end


#pragma mark - Geometry collections

/** ShapeKitPolyline is an abstract class that represents a collection of heterogeneous ShapeKitGeometry objects.
 */
@interface ShapeKitGeometryCollection : ShapeKitGeometry
- (NSUInteger)numberOfGeometries;
- (ShapeKitGeometry *)geometryAtIndex:(NSInteger)index;
@end

/** ShapeKitPolyline models a collection of ShapeKitPolyline objects.
 */
@interface ShapeKitMultiPolyline : ShapeKitGeometryCollection
- (NSUInteger)numberOfPolylines;
- (ShapeKitPolyline *)polylineAtIndex:(NSInteger)index;
@end

/** ShapeKitPoint models a collection of ShapeKitPoint objects.
 */
@interface ShapeKitMultiPoint : ShapeKitGeometryCollection
- (NSUInteger)numberOfPoints;
- (ShapeKitPoint *)pointAtIndex:(NSInteger)index;
@end

/** ShapeKitMultiPolygon models a collection of ShapeKitMultiPolygon objects.
 */
@interface ShapeKitMultiPolygon : ShapeKitGeometryCollection
- (NSUInteger)numberOfPolygons;
- (ShapeKitPolygon *)polygonAtIndex:(NSInteger)index;
@end
