//
//  WebP_Workaround.c
//  tourguide
//
//  Created by hsoi on 6/11/13.
//  Copyright (c) 2013 BarZ Adventures, Inc. All rights reserved.
//
//  When I started using SDWebImage which uses the WebP library, compiling for arm devices generated
//  linker errors:
//
//        (null): "_WebPInitPremultiplyNEON", referenced from:
//        (null): _WebPInitPremultiply in libSDWebImage.a(upsampling.o)
//        (null): "_WebPInitUpsamplersNEON", referenced from:
//        (null): _WebPInitUpsamplers in libSDWebImage.a(upsampling.o)
//        (null): "_VP8DspInitNEON", referenced from:
//        (null): _VP8DspInit in libSDWebImage.a(dec.o)
//        (null): Symbol(s) not found for architecture armv7
//        (null): Linker command failed with exit code 1 (use -v to see invocation)
//
// The problem is because in WebP's dsp.h, it checks against the __ARM_NEON__ macro and if true (which is
// is for the armv7(s) compilation), it #defines WEBP_USE_NEON. And those symbols don't exist here. I have
// no idea where those symbols are supposed to come from. But I found this:
//
// http://code.google.com/p/gmaps-api-issues/issues/detail?id=5018
//
// With a fairly recent posting by Google's own people (and apparently this all ultimately comes from
// Google). The workaround is to just define simple empty functions for them.


void WebPInitPremultiplyNEON(void);
void WebPInitUpsamplersNEON(void);
void VP8DspInitNEON(void);

void WebPInitPremultiplyNEON(void) {}
void WebPInitUpsamplersNEON(void) {}
void VP8DspInitNEON(void) {}