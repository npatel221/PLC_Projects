// import statements
#include <iostream>
#include <tuple>

/*
    This program implements an OEE calculator based on the https://www.oee.com/calculating-oee.html
    It requires 5 arguments when called:
        1. planned_production_time = minutes
        2. stop_time = minutes
        3. ideal_cycle_time = # of minutes per piece
        4. good_count = # of pieces
        5. total_count = # of pieces

    And Returns OEE parameters:
        1. Availability = %
        2. Performance = %
        3. Quality = %
        4. OEE = % 
*/

using namespace std; // set standard namespace

float CalculateRuntime(float planned_production_time, float stop_time)
{
    // Planned Production Time & Stop Time in minutes
    // Runtime calculated and returned in minutes

    float runtime = planned_production_time - stop_time;
    if (runtime < 0)
    {
        runtime = 0; // set runtime to 0 as its negative (aka bad data)
    }
    return runtime;
}

float CalculateAvailability(float planned_production_time, float run_time)
{
    // Planned Production Time & Run Time in minutes    

    float availability = run_time/planned_production_time;

    if (availability > 1 || availability < 0) // check limits
    {
        cerr << "Error in calculating availability" << endl;
        exit(1); // exit with error and terminate execution
    }
    return availability;
}

float CalculatePerformance(float ideal_cycle_time, unsigned int total_count, float run_time)
{
    // Ideal cycle time in number of minutes per piece
    // Total count in number of product pieces
    // Runtime in minutes

    float performance = (ideal_cycle_time * total_count) / run_time;

    if (performance > 1 || performance < 0) // check limits
    {
        cerr << "Error in calculating performance" << endl;
        exit(1); // exit with error and terminate execution
    }
    return performance;
}

float CalculateQuality(unsigned int good_count, unsigned int total_count)
{
    // Good count in # of pieces
    // Total count in # of pieces

    float quality = ((float) good_count) / ((float) total_count);

    if (quality > 1 || quality < 0) // check limits
    {
        cerr << "Error in calculating quality" << endl;
        exit(1); // exit with error and terminate execution
    }
    return quality;
}

tuple<float, float, float, float> CalculateOEE(float planned_production_time, float stop_time,
                   float ideal_cycle_time, unsigned int good_count, 
                   unsigned int total_count)
{
    float run_time = CalculateRuntime(planned_production_time, stop_time);

    float availability = CalculateAvailability(planned_production_time, run_time);

    float performance = CalculatePerformance(ideal_cycle_time, total_count, run_time);

    float quality = CalculateQuality(good_count, total_count);

    float oee = availability * performance * quality;

    return {availability, performance, quality, oee};
}

int main(int argc, char* argv[])
{
    // we expect 5 arguments only
    if (argc < 5 || argc > 6) 
    { 
        cerr << "Expected 5 arguments (planned_production_time, "
                "stop_time, ideal_cycle_time, good_count, total_count) but " 
                << argc << " provided.\n";
        return 1;
    }

    // extract variables from command line arguments
    float planned_production_time = atof(argv[1]);
    float stop_time = atof(argv[2]);
    float ideal_cycle_time = atof(argv[3]);
    unsigned int good_count = atoi(argv[4]);
    unsigned int total_count = atoi(argv[5]);

    // get all parameters and oee measure
    float availability, performance, quality, oee;
    tie(availability, performance, quality, oee) = CalculateOEE(planned_production_time, 
                                                                    stop_time, ideal_cycle_time, 
                                                                    good_count, total_count);

    // print all paramenters in % and oee measure in % as well
    cout << "Availability: " << availability*100 << " %\n";
    cout << "Performance: " << performance*100 << " %\n";
    cout << "Quality: " << quality*100 << " %\n";
    cout << "OEE: " << oee*100 << " %\n";

    return 0; // successful execution
}