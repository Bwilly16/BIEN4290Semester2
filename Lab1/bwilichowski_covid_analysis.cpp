#include "bwilichowski_dataset.hpp"
#include "bwilichowski_signal_utils.hpp"

int main(){

    std::unordered_map<std::string, std::vector<float>> holdValue;
    
    Dataset::myDataset blue("covid/Canada_covid_stats.csv");
    blue.load_dataset();
    holdValue = blue.GetMap();

    SignalUtils::mySignalUtils::peak_value(holdValue);

    return 0;
}