//
// Created by Pavel Akhtyamov on 02.05.2020.
//
#include "WeatherTestCase.h"
#include "WeatherMock.h"

WeatherTestCase::WeatherTestCase()
{
    bad_response = cpr::Response();
    bad_response.status_code = 100;
    good_response = cpr::Response();
    bad_response.status_code = 200;
    moscow = cpr::Response();
    moscow.status_code=200;
}
TEST_F(WeatherTestCase, GetResponseForCity)
{

    // EXPECT_CALL(weatherMock, Get("Null", url)).Times(1).WillRepeatedly(Return(bad_response));
    ASSERT_THROW(weatherMock.GetResponseForCity("Null", url), std::invalid_argument);
    
}


TEST_F(WeatherTestCase, ApiKey) {
  weatherMock.SetApiKey("test api key");
  ASSERT_EQ(weatherMock.api_key_, "test api key");
}
