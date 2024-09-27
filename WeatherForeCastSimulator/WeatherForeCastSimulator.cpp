#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;
//Define a struct for weather data
struct	Weather {
	string location;
	string date;
	string condition;
	int temperature;
	int humidity;
};
//Function to generate random weather data
Weather generateWeather(string location) {
	Weather weather;
	weather.location = location;
	//get current time
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	//format date as DD/MM/YYYY
	weather.date = to_string(ltm.tm_mday) + "/" + to_string(ltm.tm_mon + 1) + "/" + to_string(ltm.tm_year + 1900);

	//random weather conditions
	string conditions[] = { "sunny","Cloudy","Rainy", "Windy", "Snowy" };
	weather.condition = conditions[rand() % 5];
	//Rnadom Temperature('C)
	weather.temperature = rand() % 80 + 20;
	return weather;

}
//Function to display weather forecast
void displayForecast(Weather weather) {
	cout << "Weather Forecast for " << weather.location << " on " << weather.date << endl;
	cout << "Temperature: " << weather.temperature << " 'C" << endl;
	cout << "Humidity: " << weather.humidity << " %" << endl;
	cout << "Condition: " << weather.condition << " " << endl;
}

int main() {
	srand(time(0)); //set random number generator
	
	string location;
	cout << "Enter location: ";
	getline(cin, location);

	Weather weather = generateWeather(location);
	
	displayForecast(weather);
	system("PAUSE");
		return 0;
}