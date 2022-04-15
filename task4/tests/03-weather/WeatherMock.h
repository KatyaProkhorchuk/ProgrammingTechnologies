//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#pragma once

#include <gmock/gmock.h>
#include <Weather.h>
#include <cpr/cpr.h>
#include <string.h>
#include <iostream>

class WeatherMock : public Weather
{
public:
    // cpr::Response Get(const std::string &city, const cpr::Url &url)
    // {
    //     cpr::Response response;
    //     std::stringstream s;
    //     int f1, f2;
    //     s >> f1 >> f2;
    //     response.text = "{\"main\":{\"temp\":" + std::to_string(f1) + "},\"list\":[\"\",\"\",\"\",\"\",\"\",\"\",\"\",{\"main\":{\"temp\":" + std::to_string(f2) + "}}]}";
    //     response.status_code = 200;
    //     return response;
    // }
    // MOCK_METHOD(float, GetTemperature, (const std::string& city),(override));
    // MOCK_METHOD(float, GetTomorrowTemperature, (const std::string& city),(override));
    MOCK_METHOD(cpr::Response, Get, (const std::string& city, const cpr::Url& url),(override));
};
