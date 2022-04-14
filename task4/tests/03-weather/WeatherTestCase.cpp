//
// Created by Pavel Akhtyamov on 02.05.2020.
//
#include "WeatherTestCase.h"
#include "WeatherMock.h"

    
TEST(WeatherTestCase, Tests)
{
    WeatherMock weather;
    
    weather.GetTomorrowDiff("Moscow");
    weather.FindDiffBetweenTwoCities("Moscow", "Paris");
    weather.FindDiffBetweenTwoCities("Moscow", "Paris");
    weather.GetDifferenceString("Moscow", "Paris");
    weather.SetApiKey("api");
    
}