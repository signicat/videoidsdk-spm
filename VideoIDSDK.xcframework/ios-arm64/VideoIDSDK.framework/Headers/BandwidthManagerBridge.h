#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BandwidthResult) {
    BandwidthResultFrameStop = 1,
    BandwidthResultFrameResume = 2,
    BandwidthResultS3Stop = 3,
    BandwidthResultS3Resume = 4,
    BandwidthResultPNGStop = 5,
    BandwidthResultPNGResume = 6,
};

typedef void (^BandwidthResultBlock)(BandwidthResult result);

@interface Adhoc3Stats : NSObject

@property (nonatomic, strong, readonly, nullable) NSNumber *controlLatency;
@property (nonatomic, strong, readonly, nullable) NSNumber *frameLatency;

- (instancetype)initWithControlLatency:(nullable NSNumber *)controlLatency
                          frameLatency:(nullable NSNumber *)frameLatency;

@end

@interface BandwidthUploadSampleSnapshot : NSObject

@property (nonatomic, readonly) double size;
@property (nonatomic, readonly) NSInteger uploadTime;

- (instancetype)initWithSize:(double)size uploadTime:(NSInteger)uploadTime;

@end

@interface BandwidthAnalyticsSnapshot : NSObject

@property (nonatomic, copy, readonly) NSArray<NSNumber *> *controlLatency;
@property (nonatomic, copy, readonly) NSArray<NSNumber *> *frameLatency;
@property (nonatomic, copy, readonly) NSArray<BandwidthUploadSampleSnapshot *> *frameBandwidth;
@property (nonatomic, copy, readonly) NSArray<BandwidthUploadSampleSnapshot *> *s3Bandwidth;
@property (nonatomic, copy, readonly) NSArray<BandwidthUploadSampleSnapshot *> *pngBandwidth;

- (instancetype)initWithControlLatency:(NSArray<NSNumber *> *)controlLatency
                          frameLatency:(NSArray<NSNumber *> *)frameLatency
                        frameBandwidth:(NSArray<BandwidthUploadSampleSnapshot *> *)frameBandwidth
                           s3Bandwidth:(NSArray<BandwidthUploadSampleSnapshot *> *)s3Bandwidth
                          pngBandwidth:(NSArray<BandwidthUploadSampleSnapshot *> *)pngBandwidth;

@end

@interface BandwidthManagerBridge : NSObject

/// Sets the listener that receives bandwidth/congestion result codes.
- (void)setBWListener:(nullable BandwidthResultBlock)listener;

/// Clears the current listener if this bridge owns it.
- (void)clearBWListener;

/// Applies all SDK-validated bandwidth thresholds together.
- (void)configureWithControlRTTThreshold:(double)controlRTTThreshold
                    frameRTTLowThreshold:(double)frameRTTLowThreshold
                 frameRTTMediumThreshold:(double)frameRTTMediumThreshold
                   frameRTTHighThreshold:(double)frameRTTHighThreshold
                    s3BandwidthThreshold:(double)s3BandwidthThreshold
                   pngBandwidthThreshold:(double)pngBandwidthThreshold;

/// Feeds control-channel latency in milliseconds.
- (void)feedControlPing:(int64_t)millis;

/// Feeds frame-channel latency in milliseconds.
- (void)feedFramePing:(int64_t)millis;

/// Feeds detection-frame bandwidth sample size and duration in milliseconds.
- (void)feedFrameBandwidthWithSize:(NSInteger)size millis:(int64_t)millis;

/// Feeds S3 bandwidth sample size and duration in milliseconds.
- (void)feedS3BandwidthWithSize:(NSInteger)size millis:(int64_t)millis;

/// Forwards PNG bandwidth sample size and duration to the shared manager's feedPngBandwidth method.
- (void)feedPNGBandwidthWithSize:(NSInteger)size millis:(int64_t)millis;

/// Returns the raw bandwidth analytics accumulated by the shared native manager.
- (BandwidthAnalyticsSnapshot *)bandwidthAnalytics;

/// Returns the latest control and frame latency values recorded by the shared native manager.
- (Adhoc3Stats *)getStats;

/// Clears the raw bandwidth analytics accumulated by the shared native manager.
- (void)resetBandwidthAnalytics;

@end

NS_ASSUME_NONNULL_END
