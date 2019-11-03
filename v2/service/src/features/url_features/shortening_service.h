#pragma once

#ifndef PHISHSVC_FEATURE_SHORTENING_SERVICE_H
#define PHISHSVC_FEATURE_SHORTENING_SERVICE_H

#include <string>

#include "../feature_base.h"

namespace feature {
class shortening_service: public base {
public:
    double compute_value() override;
};

} // namespace feature

#endif // PHISHSVC_FEATURE_SHORTENING_SERVICE_H
