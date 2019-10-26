#include <Poco/Exception.h>
#include <fmt/format.h>

#include "feature_base.h"


namespace feature {

void base::set_url(const std::string& url)
{
    _url = url;
    try {
        _url_obj = Poco::URI(url);
        _url_is_ok = true;
    } catch (const Poco::SyntaxException& ex) {
        fmt::print(stderr, "Error. URL '{}' is malformed.\n", url);
        _url_obj = Poco::URI();
    }
}

} // namespace feature

