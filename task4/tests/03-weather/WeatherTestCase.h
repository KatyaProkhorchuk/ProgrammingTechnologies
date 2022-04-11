
#pragma once

#include <gtest/gtest.h>

#include <cpr/cpr.h>
#define private public

#include "WeatherMock.h"
using ::testing::_;
class WeatherTestCase : public ::testing::Test {
    public:
        WeatherMock weatherMock;
        cpr::Response bad_response;
        cpr::Response good_response;
        cpr::Response moscow,kaliningrad;
        cpr::Url url1={"https://www.gismeteo.ru/"};
        cpr::Url url;
        WeatherTestCase();
};



