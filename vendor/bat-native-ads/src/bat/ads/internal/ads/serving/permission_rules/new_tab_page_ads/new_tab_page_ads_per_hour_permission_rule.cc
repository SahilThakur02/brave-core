/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/ads/serving/permission_rules/new_tab_page_ads/new_tab_page_ads_per_hour_permission_rule.h"

#include "base/time/time.h"
#include "bat/ads/ad_type.h"
#include "bat/ads/confirmation_type.h"
#include "bat/ads/internal/ads/ad_events/ad_events.h"
#include "bat/ads/internal/ads/serving/serving_features.h"
#include "bat/ads/internal/base/time/time_constraint_util.h"

namespace ads::new_tab_page_ads {

namespace {
constexpr base::TimeDelta kTimeConstraint = base::Hours(1);
}  // namespace

bool AdsPerHourPermissionRule::ShouldAllow() {
  const std::vector<base::Time> history =
      GetAdEventHistory(AdType::kNewTabPageAd, ConfirmationType::kServed);

  if (!DoesRespectCap(history)) {
    last_message_ = "You have exceeded the allowed new tab page ads per hour";
    return false;
  }

  return true;
}

const std::string& AdsPerHourPermissionRule::GetLastMessage() const {
  return last_message_;
}

bool AdsPerHourPermissionRule::DoesRespectCap(
    const std::vector<base::Time>& history) {
  return DoesHistoryRespectRollingTimeConstraint(
      history, kTimeConstraint, features::GetMaximumNewTabPageAdsPerHour());
}

}  // namespace ads::new_tab_page_ads
