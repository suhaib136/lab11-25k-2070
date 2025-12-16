#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct WeatherData {
    char cityName[50];
    float baseTemp;
    float coolingFactor;
};

float predictTemp(int day, float prevTemp, struct WeatherData w) {
    if (day == 0)
        return prevTemp;

    float variation = (rand() % 400 - 200) / 100.0;
    float todayTemp = prevTemp + variation - w.coolingFactor;

    printf("Day %d Temperature = %.2f°C\n", day, todayTemp);

    return predictTemp(day - 1, todayTemp, w);
}

int main() {
    srand(time(NULL));

    struct WeatherData w;

    printf("Enter city name: ");
    scanf("%s", w.cityName);

    printf("Enter base temperature: ");
    scanf("%f", &w.baseTemp);

    printf("Enter cooling factor: ");
    scanf("%f", &w.coolingFactor);

    int days;
    printf("Enter number of days to simulate: ");
    scanf("%d", &days);

    printf("\n--- Weather Forecast for %s ---\n", w.cityName);

    predictTemp(days, w.baseTemp, w);

    return 0;
}
