/* Copyright (c) 2023 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_ADS_CORE_INTERNAL_USER_USER_INTERACTION_AD_EVENTS_PROMOTED_CONTENT_ADS_PROMOTED_CONTENT_AD_EVENT_HANDLER_DELEGATE_MOCK_H_
#define BRAVE_COMPONENTS_BRAVE_ADS_CORE_INTERNAL_USER_USER_INTERACTION_AD_EVENTS_PROMOTED_CONTENT_ADS_PROMOTED_CONTENT_AD_EVENT_HANDLER_DELEGATE_MOCK_H_

#include <string>

#include "brave/components/brave_ads/core/internal/user/user_interaction/ad_events/promoted_content_ads/promoted_content_ad_event_handler_delegate.h"
#include "testing/gmock/include/gmock/gmock.h"

namespace brave_ads {

class PromotedContentAdEventHandlerDelegateMock
    : public PromotedContentAdEventHandlerDelegate {
 public:
  PromotedContentAdEventHandlerDelegateMock();

  PromotedContentAdEventHandlerDelegateMock(
      const PromotedContentAdEventHandlerDelegateMock&) = delete;
  PromotedContentAdEventHandlerDelegateMock& operator=(
      const PromotedContentAdEventHandlerDelegateMock&) = delete;

  PromotedContentAdEventHandlerDelegateMock(
      PromotedContentAdEventHandlerDelegateMock&&) noexcept = delete;
  PromotedContentAdEventHandlerDelegateMock& operator=(
      PromotedContentAdEventHandlerDelegateMock&&) noexcept = delete;

  ~PromotedContentAdEventHandlerDelegateMock() override;

  MOCK_METHOD(void,
              OnDidFirePromotedContentAdServedEvent,
              (const PromotedContentAdInfo& ad));

  MOCK_METHOD(void,
              OnDidFirePromotedContentAdViewedEvent,
              (const PromotedContentAdInfo& ad));

  MOCK_METHOD(void,
              OnDidFirePromotedContentAdClickedEvent,
              (const PromotedContentAdInfo& ad));

  MOCK_METHOD(void,
              OnFailedToFirePromotedContentAdEvent,
              (const std::string& placement_id,
               const std::string& creative_instance_id,
               const mojom::PromotedContentAdEventType event_type));
};

}  // namespace brave_ads

#endif  // BRAVE_COMPONENTS_BRAVE_ADS_CORE_INTERNAL_USER_USER_INTERACTION_AD_EVENTS_PROMOTED_CONTENT_ADS_PROMOTED_CONTENT_AD_EVENT_HANDLER_DELEGATE_MOCK_H_
