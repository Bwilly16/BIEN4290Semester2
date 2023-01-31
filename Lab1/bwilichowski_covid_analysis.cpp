#include "bwilichowski_dataset.hpp"
#include "bwilichowski_signal_utils.hpp"

int main(){
    
    Dataset::myDataset blue("covid/Canada_covid_stats.csv");
    blue.load_dataset();
    return 0;
}