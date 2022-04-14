
#pragma once

#include <gtest/gtest.h>

#include <cpr/cpr.h>

#include "WeatherMock.h"
class WeatherTestCase : public ::testing::Test
{
public:
    WeatherMock weatherMock;
    
};
