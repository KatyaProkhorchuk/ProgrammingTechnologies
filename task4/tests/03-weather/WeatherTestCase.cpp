//
// Created by Pavel Akhtyamov on 02.05.2020.
//
#include "WeatherTestCase.h"
#include "WeatherMock.h"
#include "string.h"
using ::testing::Return;

TEST(WeatherTestCase, Tests)
{
    Weather weather;
    const cpr::Url kBaseUrl = cpr::Url{"http://api.openweathermap.org/data/2.5/weather"};
    const cpr::Url kForecastUrl = cpr::Url{"http://api.openweathermap.org/data/2.5/forecast"};
    testing::NiceMock<WeatherMock> weatherMock;
    float temp_msc, temp_paris;
    ASSERT_THROW(weather.GetTemperature(")))"), std::invalid_argument);
    // weather.SetApiKey("weather");

    // std::string key = "22895a60d7c10a6d37075ebd21220122";
    // cpr::Response moscow = cpr::Get(kBaseUrl, cpr::Parameters{
    //                                               {"q", "Moscow"},
    //                                               {"appid", key},
    //                                               {"units", "metric"}});
    // cpr::Response paris = cpr::Get(kBaseUrl, cpr::Parameters{
    //                                              {"q", "Paris"},
    //                                              {"appid", key},
    //                                              {"units", "metric"}});
    // json json_paris = json::parse(paris.text);
    // json json_msc = json::parse(moscow.text);
    // temp_msc = json_msc["main"]["temp"];
    // temp_paris = json_paris["main"]["temp"];

    // ON_CALL(weatherMock, Get("Moscow", kBaseUrl)).WillByDefault(Return(moscow));
    // ON_CALL(weatherMock, Get("Paris", kBaseUrl)).WillByDefault(Return(paris));
    // float temp_weather_paris = weatherMock.GetTemperature("Paris");
    // float temp_weather_msc = weatherMock.GetTemperature("Moscow");
    // ASSERT_EQ(temp_msc, temp_weather_msc);
    // ASSERT_EQ(temp_paris, temp_weather_paris);
    // std::string DiffStrings = weatherMock.GetDifferenceString("Moscow", "Paris");
    // std::string resultDiff = "";
    // int diff = temp_paris - temp_msc;
    // if (temp_msc < temp_paris)
    // {
    //     resultDiff += "Weather in Moscow is colder than in Paris by ";
    //     resultDiff += std::to_string(diff);
    //     resultDiff += " degrees";
    // }
    // else
    // {
    //     resultDiff += "Weather in Moscow is warmer than in Paris by ";
    //     resultDiff += std::to_string(-diff);
    //     resultDiff += " degrees";
    // }
    // ASSERT_EQ(DiffStrings, resultDiff);
    // DiffStrings = weatherMock.GetDifferenceString("Paris", "Moscow");
    // resultDiff = "";
    // diff = temp_msc - temp_paris;
    // if (temp_paris < temp_msc)
    // {
    //     resultDiff += "Weather in Paris is colder than in Moscow by ";
    //     resultDiff += std::to_string(diff);
    //     resultDiff += " degrees";
    // }
    // else
    // {
    //     resultDiff += "Weather in Paris is warmer than in Moscow by ";
    //     resultDiff += std::to_string(-diff);
    //     resultDiff += " degrees";
    // }
    // ASSERT_EQ(DiffStrings, resultDiff);
    // cpr::Response moscow_1 = cpr::Get(kForecastUrl, cpr::Parameters{
    //                                                     {"q", "Moscow"},
    //                                                     {"appid", key},
    //                                                     {"units", "metric"}});
    // ON_CALL(weatherMock, Get("Moscow", kForecastUrl)).WillByDefault(Return(moscow_1));
    // json json_msc_1 = json::parse(moscow_1.text);
    // float temp_weather_msc_1 = weatherMock.GetTemperature("Moscow");
    // float temp_msc_1 = weatherMock.GetTomorrowTemperature("Moscow");
    // ASSERT_EQ(temp_msc_1, float(json_msc_1["list"][7]["main"]["temp"]));
    // std::string test_get_tom_diff = "The weather in Moscow tomorrow will be ";
    // float diff_1 = float(json_msc_1["list"][7]["main"]["temp"]) - temp_msc;
    // if (diff_1 > 3)
    // {
    //     test_get_tom_diff += "much warmer";
    // }
    // else if (diff_1 > 0.5)
    // {
    //     test_get_tom_diff += "warmer";
    // }
    // else if (diff_1 < -3)
    // {
    //     test_get_tom_diff += "much colder";
    // }
    // else if (diff_1 < -0.5)
    // {
    //     test_get_tom_diff += "colder";
    // }
    // else
    // {
    //     test_get_tom_diff += "the same";
    // }
    // test_get_tom_diff += " than today.";
    // std::string gtd = weatherMock.GetTomorrowDiff("Moscow");
    // ASSERT_EQ(test_get_tom_diff,gtd);
}