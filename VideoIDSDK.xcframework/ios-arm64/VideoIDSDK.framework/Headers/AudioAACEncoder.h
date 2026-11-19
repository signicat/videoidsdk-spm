//
//  AudioAACEncoder
//
//  Created by Alberto Pérez Pérez on 19/03/2020.
//  Copyright © 2020 Electronic ID. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AudioAACEncoder : NSObject

///
/// Encodes the provided audio sample in PCM format to AAC
///
/// @param sampleBuffer the sample buffer containing the pcm.
/// @param completionBlock provides the resulting encoded audio data if available or the error if exists.
///
- (void)encodeSampleBuffer:(CMSampleBufferRef)sampleBuffer
           completionBlock:(void (^)(NSData * _Nullable encodedData, NSError * _Nullable error))completionBlock;

@end

NS_ASSUME_NONNULL_END
