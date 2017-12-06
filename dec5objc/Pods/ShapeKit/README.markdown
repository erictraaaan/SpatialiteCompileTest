# ShapeKit


ShapeKit is a iOS/OSX library that offers an Objective-C interface to the powerful [GEOS](http://trac.osgeo.org/geos/) library.
Through GEOS, ShapeKit includes all the OpenGIS Simple Features for SQL spatial predicate functions and spatial operators, as well as specific JTS enhanced topology functions.
This fork is based on the [original repository](https://github.com/mweisman/ShapeKit) by Michael Weisman, with major customizations.
- ShapeKit has been refactored to build in a static library (libShapeKit.a)
- Apple's MapKit specific methods have been refactored in a dedicated category to generalize the code and remove Apple's MapKit dependency. ShapeKit just takes care of the model, so that you can choose the map library you prefer (Apple's MapKit, route-me in the [original flavour](https://github.com/route-me/route-me) or in [Alpstein](http://github.com/Alpstein) or [Mapbox](https://github.com/mapbox/mapbox-ios-sdk) forks ecc..)
- GEOS linearref functions (project and interpolate on a line) support was added


## Usage

* ShapeKitGeometries are standard cocoa objects

```objc
ShapeKitPoint *myPoint = [[ShapeKitPoint alloc] initWithCoordinate:CLLocationCoordinate2DMake(0, 0)];
```

* ShapeKit has spatial predicates and topology operations

```objc
ShapeKitPolygon *bufferedPoint = [myPoint bufferWithWidth:0.005]
[bufferedPoint containsGeometry:myPoint]; // Returns YES
```

* ShapeKit has support for linear projection and interpolation 

```objc
ShapeKitPoint *middlePoint = [myLine interpolatePointAtNormalizedDistance: 0.5];
double projectedPosition = [myLine distanceFromOriginToProjectionOfPoint: myPoint];
```

## Project setup

### CocoaPods
The easy way is using CocoaPods: since mingling with ShapeKit's dependencies is not that easy, you are strongly encouraged to get this path.

But before you must install the [GNU build system](http://en.wikipedia.org/wiki/GNU_build_system) if you haven't already:

```bash
brew install automake autoconf libtool
```

Now you can create your Podfile as usual:

```ruby
platform :ios, '5.0'
pod 'ShapeKit'
```

and execute ```pod install```

Now an extra step is required: ShapeKit resides on C++ libraries and we should tell the compiler that our project files should be treated as Objective-C++. Just rename your main file `main.m` to `main.mm` and the trick is done.

Now you should be able to use Shapekit in your project, just `#import <ShapeKit/ShapeKit.h>` in your .m files


## License

This is free software; you can redistribute and/or modify it under the terms of the GNU Lesser General Public Licence as published by the Free Software Foundation. See the COPYING file for more information.

**License note: Be aware that LGPL v2.1 (GEOS license) and Apple Store compatibility is at least controversial** (search for "LGPL iOS" on Google to know why).
