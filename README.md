# VoltageGraph

- Uses an Arduino to read voltages on the analog pins.(A1-2)
- First pin is an referance pin. (A0)
- Returns(Serial:115200) a JSON string with Min, Max, Avg. (by default it will do 100 readings per cycle) 

Output Example:
{
    "MIN": [
        0,
        0,
        0
    ],
    "MAX": [
        10,
        9,
        8
    ],
    "AVG": [
        0.36,
        0.33,
        0.27
    ] 
}
