#include "PlaceDescriptionService.h"
#include "Http.h"
#include "AddressExtractor.h"
#include "Address.h"
#include <string>

using namespace std;

PlaceDescriptionService::PlaceDescriptionService(Http* http) : http_(http) {}

string PlaceDescriptionService::summaryDescription( const string& latitude, const string& longitude) const
{
    string urlStart("http://open.mapquestapi.com/nominatim/v1/reverse?format=json&");
    auto getRequestUrl = urlStart + "lat=" + latitude + "&lon=" + longitude;
    auto jsonResponse = http_->get(getRequestUrl);

    AddressExtractor extractor;
    auto address = extractor.addressFrom(jsonResponse);
    return address.road + ", " + address.city + ", " +
           address.state + ", " + address.country;
}

