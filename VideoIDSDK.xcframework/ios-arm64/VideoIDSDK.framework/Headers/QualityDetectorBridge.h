//
//  QualityDetectorBridge.h
//  VideoIDSDK
//
//  ObjC++ bridge wrapping the C++ QualityDetector for face quality checks.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface QualityDetectorBridge : NSObject

///
/// Applies filter configuration for face quality checks.
/// Expected dictionary shape (subset of the PipelineConfig filters array):
///
/// {
///   "filters": [
///     { "filterName": String, "thresholds": {String: Number}, "properties": {"ratios": [Number]} }
///   ]
/// }
///
/// Recognised filterName values: "FaceBlurDetector", "FaceLuminanceDetector", "FaceEnvLuminanceDetector".
/// Filters with missing or invalid thresholds are silently skipped.
///
/// @param configuration the quality filter configuration dictionary.
///
- (void)setConfiguration:(NSDictionary *)configuration;

///
/// Runs face quality checks on the provided video sample buffer.
/// Extracts Y+UV planes from a 420v/420f CVPixelBuffer, converts to BGR,
/// then evaluates the configured quality filters on the face ROI.
/// Processing is performed on a serial dispatch queue.
///
/// @param sampleBuffer the camera sample buffer (video frame).
/// @param roi array of 4 {"x":Int,"y":Int} dicts defining the face bounding box in pixel coords (top-left origin, clockwise).
/// @param completionBlock provides the quality result on the callback queue.
///   - success: YES if all active quality filters passed.
///   - notificationName: semantic result token (e.g. "FACE_OK", "IMAGE_BLURRED", "LUMINANCE_TOO_LOW").
///   - filter: name of the filter that produced the result.
///   - report: human-readable detail string.
///
- (void)processFrame:(CMSampleBufferRef)sampleBuffer
                 roi:(NSArray<NSDictionary *> *)roi
     completionBlock:(void (^)(BOOL success,
                               NSString *notificationName,
                               NSString *filter,
                               NSString *report))completionBlock;

@end

NS_ASSUME_NONNULL_END
