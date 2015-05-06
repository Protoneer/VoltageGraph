# VoltageGraph

- Uses an Arduino to read voltages on the analog pins.(A1-2)
- First pin is an referance pin. (A0)
- Returns(Serial:115200) a JSON string with Min, Max, Avg. (by default it will do 100 readings per cycle) 

Output Example:
{
    "MIN": {
        "LV1": 0,
        "LV2": 0,
        "REF": 0
    },
    "MAX": {
        "LV1": 784,
        "LV2": 784,
        "REF": 769
    },
    "AVG": {
        "LV1": 781.38,
        "LV2": 781.36,
        "REF": 766.41
    }
}
