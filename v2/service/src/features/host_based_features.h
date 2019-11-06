#pragma once

#ifndef PHISHSVC_FEATURE_HOST_BASED_FEATURES_H
#define PHISHSVC_FEATURE_HOST_BASED_FEATURES_H

#include "feature_enum.h"

#include <regex>
#include <string_view>
#include <vector>

#include <Poco/URI.h>

class host_based_features_t {
public:
    explicit host_based_features_t(const std::string_view url);
    host_based_features_t(const std::string_view url, const Poco::URI& parsed,
        const uint64_t flags, const bool url_is_ok);

    std::vector<double> compute_values_vec() const;
    std::unordered_map<feature_enum::id, double> compute_values_map() const;
    double compute_value(feature_enum::id feature) const;
    double compute_value_redirect() const;
    double compute_value_google_indexed() const;
    double compute_value_dns_a_record() const;
    double compute_value_dnssec() const;
    double compute_value_dns_created() const;
    double compute_value_dns_updated() const;
    std::string extract_dns_date(bool created) const;
    double compute_value_ssl_subject() const;
    double compute_value_ssl_subject(bool);


private:
    const std::string_view _url;
    const uint64_t _flags{0};
    const Poco::URI _parsed{};
    const bool _url_is_ok{false};

    const std::string_view _user_agent{"user-agent: Mozilla/5.0 (X11; Fedora; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.70 Safari/537.36"};

    std::vector<std::string> ssl_response_;

    std::string extract_value(const std::vector<std::string>& output, const std::regex& reg) const;
    std::string extract_value_from_output(const std::vector<std::string>& output, const std::regex& reg) const;
    std::vector<std::string>  get_ssl_response() const;
    std::string get_ssl_subject() const;
    void fill_ssl_response();
};

#endif // PHISHSVC_FEATURE_HOST_BASED_FEATURES_H
