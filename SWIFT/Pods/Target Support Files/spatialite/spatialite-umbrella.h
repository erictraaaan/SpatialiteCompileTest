#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "spatialite.h"
#import "spatialite/debug.h"
#import "spatialite/gaiaaux.h"
#import "spatialite/gaiaexif.h"
#import "spatialite/gaiageo.h"
#import "spatialite/geopackage.h"
#import "spatialite/gg_advanced.h"
#import "spatialite/gg_const.h"
#import "spatialite/gg_core.h"
#import "spatialite/gg_dxf.h"
#import "spatialite/gg_dynamic.h"
#import "spatialite/gg_formats.h"
#import "spatialite/gg_mbr.h"
#import "spatialite/gg_structs.h"
#import "spatialite/gg_wfs.h"
#import "spatialite/gg_xml.h"
#import "spatialite/spatialite.h"
#import "spatialite/sqlite.h"

FOUNDATION_EXPORT double spatialiteVersionNumber;
FOUNDATION_EXPORT const unsigned char spatialiteVersionString[];

