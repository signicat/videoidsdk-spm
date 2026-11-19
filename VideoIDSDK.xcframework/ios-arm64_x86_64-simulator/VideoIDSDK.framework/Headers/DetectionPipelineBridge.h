//
//  DetectionPipelineBridge.h
//  VideoIDSDK
//
//  ObjC++ bridge wrapping the C++ detection_pipeline for use from Swift.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@interface DetectionPipelineBridge : NSObject

/// Semantic version of the linked cvlibpipelineadapter library.
+ (NSString *)adapterVersion;

///
/// Applies the active filter configuration (sent by the backend in the clientTerms response)
/// to the underlying pipeline. Expected dictionary shape:
///
/// {
///   "debug": Bool,
///   "detectionRoi": [{"x":Int,"y":Int}, ... 4 points],
///   "fitnessRoi": [{"x":Int,"y":Int}, ... 4 points],
///   "filters": [
///     { "filterName": String, "thresholds": {String: Number}, "properties": {"ratios": [Number]} }
///   ]
/// }
///
/// A filter is silently disabled by the pipeline if its required configuration is missing or invalid.
///
/// @param configuration the filter configuration dictionary.
///
- (void)setConfiguration:(NSDictionary *)configuration;

/// Seeds the object tracker from the same camera frame used for the accepted
/// scan. Call while RectDetector is configured, before switching to ObjectTracker.
/// A failed seed clears any previous reference to prevent stale identity.
- (void)setTrackingReferenceFromSampleBuffer:(CMSampleBufferRef)sampleBuffer
                             completionBlock:(void (^)(BOOL success))completionBlock;

/// Clears the document identity carried into a later hologram/OVF phase.
- (void)clearTrackingReference;

///
/// Runs the active filter pipeline on the provided video sample buffer.
/// Extracts the Y+UV planes from a 420v/420f CVPixelBuffer and converts to BGR.
/// Processing is performed on a serial dispatch queue.
///
/// @param sampleBuffer the camera sample buffer (video frame).
/// @param completionBlock provides the pipeline result on the callback queue.
///
- (void)processFrame:(CMSampleBufferRef)sampleBuffer
     completionBlock:(void (^)(BOOL success,
                               NSString * _Nullable notificationName,
                               NSString * _Nullable filter,
                               NSString * _Nullable report))completionBlock;

@end

NS_ASSUME_NONNULL_END
