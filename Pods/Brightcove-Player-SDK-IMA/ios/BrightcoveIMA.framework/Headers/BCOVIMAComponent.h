//
// BCOVIMAComponent.h
// BrightcoveIMA
//
// Copyright (c) 2016 Brightcove, Inc. All rights reserved.
// License: https://accounts.brightcove.com/en/terms-and-conditions
//

#import <Foundation/Foundation.h>

#import <BrightcovePlayerSDK/BrightcovePlayerSDK.h>

@class BCOVIMAAdsRequestPolicy;
@class IMAAdsRenderingSettings;
@class IMASettings;


extern NSString * const kBCOVIMALifecycleEventAdsLoaderLoaded;
extern NSString * const kBCOVIMALifecycleEventPropertyKeyAdsManager;
extern NSString * const kBCOVIMALifecycleEventAdsLoaderFailed;
extern NSString * const kBCOVIMALifecycleEventAdsManagerDidReceiveAdEvent;
extern NSString * const kBCOVIMALifecycleEventPropertyKeyAdEvent;
extern NSString * const kBCOVIMALifecycleEventAdsManagerDidReceiveAdError;
extern NSString * const kBCOVIMALifecycleEventPropertyKeyAdError;
extern NSString * const kBCOVIMALifecycleEventAdsManagerDidRequestContentPause;
extern NSString * const kBCOVIMALifecycleEventAdsManagerDidRequestContentResume;

extern NSString * const kBCOVIMAAdPropertiesKeyIMAAdInstance;

/**
 * The default ad tag policy will look for an entry in each session.video's
 * properties with this key and use it as the ad tag for VMAP requests. In
 * other words, each video for which ad rules have been configured should have
 * this key in its properties, and the value should be the ad tag for the VMAP
 * response to use for the rest of the video's ad breaks.
 */
extern NSString * const kBCOVIMAAdTag;

/**
 * The cue point type for IMA ad type.
 */
extern NSString * const kBCOVIMACuePointTypeAd;

/**
 * The dictionary key in the video properties for the
 * IMA ad display container (IMAAdDisplayContainer *) associated with this ad.
 * May be present in BCOVVideo objects returned in BCOVPlaybackControllerAdsDelegate
 * callbacks (the video object is accessible via the session object).
 */
extern NSString * const kBCOVIMAVideoPropertiesKeyAdDisplayContainer;

/**
 * Category methods added to BCOVPlayerSDKManager to support IMA.
 */
@interface BCOVPlayerSDKManager (BCOVIMAAdditions)

/**
 * Creates and returns a new playback controller with the specified IMASettings
 * object, IMAAdsRenderingSettings object, view strategy, and ad container. The 
 * returned playback controller will be configured with an IMA session provider.
 *
 * @param settings An IMASettings that will be used to configure any
 * IMAAdsLoader object used by the returned playback controller.
 * @param adsRenderingSettings An IMAAdsRenderingSettings that will be used to
 * configure any IMAAdsManager object used by the returned playback controller.
 * @param adsRequestPolicy BCOVIMAAdsRequestPolicy instance to generate 
 * IMAAdsRequests for use by a given input playback session.
 * @param strategy A view strategy that determines the view for the returned
 * playback controller.
 * @param adContainer the view in which the ad will be displayed and the ad 
 * information UI will be rendered.
 * @param companionSlots the list of IMACompanionAdSlot instances. Can be nil 
 * or empty.
 * @return A new playback controller with the specified parameters.
 */
- (id<BCOVPlaybackController>)createIMAPlaybackControllerWithSettings:(IMASettings *)settings adsRenderingSettings:(IMAAdsRenderingSettings *)adsRenderingSettings adsRequestPolicy:(BCOVIMAAdsRequestPolicy *)adsRequestPolicy adContainer:(UIView *)adContainer companionSlots:(NSArray *)companionSlots viewStrategy:(BCOVPlaybackControllerViewStrategy)strategy;

/**
 * Creates and returns a new BCOVIMASessionProvider with the specified
 * parameters.
 *
 * @param settings An IMASettings that will be used to configure any
 * IMAAdsLoader object used by the returned session provider.
 * @param adsRenderingSettings An IMAAdsRenderingSettings that will be used to
 * configure any IMAAdsManager object used by the returned session provider.
 * @param adsRequestPolicy BCOVIMAAdsRequestPolicy instance to generate
 * IMAAdsRequests for use by a given input playback session.
 * @param adContainer the view in which the ad will be displayed and the ad 
 * information UI will be rendered.
 * @param companionSlots the list of IMACompanionAdSlot instances. Can be nil 
 * or empty.
 * @param provider A session provider to attach upstream and deliver playback
 * sessions to the returned session provider.
 * @return A new BCOVIMASessionProvider with the specified parameters.
 */
- (id<BCOVPlaybackSessionProvider>)createIMASessionProviderWithSettings:(IMASettings *)settings adsRenderingSettings:(IMAAdsRenderingSettings *)adsRenderingSettings adsRequestPolicy:(BCOVIMAAdsRequestPolicy *)adsRequestPolicy adContainer:(UIView *)adContainer companionSlots:(NSArray *)companionSlots upstreamSessionProvider:(id<BCOVPlaybackSessionProvider>)provider;

@end


/**
 * IMA specific methods for the plugin context.
 */
@interface BCOVSessionProviderExtension (BCOVIMAAdditions)

/**
 * Plays the video.
 *
 * On first play, before playing content, the session will process all preroll ads before starting
 * the content.
 */
- (void)ima_play;

/**
 * Pauses the video.
 */
- (void)ima_pause;

@end
