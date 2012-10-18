/*
 * Copyright (C) 2012 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ewk_intent_service_private_h
#define ewk_intent_service_private_h

#if ENABLE(WEB_INTENTS_TAG)

#include "WKEinaSharedString.h"
#include "WKIntentServiceInfo.h"
#include <WebKit2/WKBase.h>
#include <wtf/PassRefPtr.h>
#include <wtf/RefCounted.h>

/**
 * \struct Ewk_Intent_Service
 * @brief Contains the intent service data.
 */
class Ewk_Intent_Service : public RefCounted<Ewk_Intent_Service> {
public:
    WKEinaSharedString action;
    WKEinaSharedString type;
    WKEinaSharedString href;
    WKEinaSharedString title;
    WKEinaSharedString disposition;

    static PassRefPtr<Ewk_Intent_Service> create(WKIntentServiceInfoRef serviceRef)
    {
        return adoptRef(new Ewk_Intent_Service(serviceRef));
    }

private:
    explicit Ewk_Intent_Service(WKIntentServiceInfoRef serviceRef)
        : action(AdoptWK, WKIntentServiceInfoCopyAction(serviceRef))
        , type(AdoptWK, WKIntentServiceInfoCopyType(serviceRef))
        , href(AdoptWK, WKIntentServiceInfoCopyHref(serviceRef))
        , title(AdoptWK, WKIntentServiceInfoCopyTitle(serviceRef))
        , disposition(AdoptWK, WKIntentServiceInfoCopyDisposition(serviceRef))
    { }
};

#endif // ENABLE(WEB_INTENTS_TAG)

#endif // ewk_intent_service_private_h