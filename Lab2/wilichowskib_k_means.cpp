#include "wilichowskib_k_means.hpp"


cluster::mycluster::mycluster()
{

}

void cluster::mycluster::setname(std::string name)
{
  this->objname = name;
}

void cluster::mycluster::setmean(float mean)
{
  this->objmean = mean;
}

float cluster::mycluster::getmean()
{
  return objmean;
}

std::string cluster::mycluster::getname()
{
  return objname;
}

float cluster::mycluster::distfunc(float stuff)
{
  float length = 0.0;
  float objmean = this->objmean;

  length = abs(stuff - objmean);
  return length;
}

void cluster::mycluster::put_mean(std::vector<float>* temp)
{
  float mean1 = 0;
  for(float b: *temp){
    mean1 = mean1 + b;
  }
  mean1 = mean1/temp->size();
  this->newmean = mean1;
}

float cluster::mycluster::get_newmean()
{
  return this->newmean;
}

int main(int argc, char *argv[])
{
    float temp, d1, d2, d3;
    //read in and check if file exitst (WORKS)
    std::string argument1 = argv[1]; //name of log file
    std::vector<float> log_array;

    std::ifstream logfile(argument1);
    if(logfile)
    {
      std::cout<< "log file exists" << std::endl;

    } 
    else 
    {
      std::cout<< "ERROR: log file doesn't exist. EXITING PROGRAM" << std::endl;
      exit(1);
    }

    //store log file input into hold array
    while(logfile >> temp)
    {
        log_array.push_back(temp);
    }
    // std::cout << "log file vector: " << std::endl;
    // for(uint i = 0; i<log_array.size(); i++){
    //     std::cout << log_array.at(i) << std::endl;
    // }


    //set up clusters
    cluster::mycluster cluster1;
    cluster::mycluster cluster2;
    cluster::mycluster cluster3;

    //set names
    cluster1.setname("Surpressed");
    cluster2.setname("Stationary");
    cluster3.setname("Expressed");
    
    
    //set means
    cluster1.setmean(-0.5);
    cluster2.setmean(0.0);
    cluster3.setmean(0.5);

    std::cout << "C1 name: " << cluster1.getname() << std::endl;
    std::cout << "C1 mean: " << cluster1.getmean() << std::endl;
    std::cout << "C2 name: " << cluster2.getname() << std::endl;
    std::cout << "C2 mean: " << cluster2.getmean() << std::endl;
    std::cout << "C3 name: " << cluster3.getname() << std::endl;
    std::cout << "C3 mean: " << cluster3.getmean() << std::endl;


    //fore each loop = each points distance to cluster means
    float criteria = 1.0;

    while(criteria > 0.0001){
      for(float temp : log_array){ //for each line in the log array...
        

        d1 = cluster1.distfunc(temp);
        d2 = cluster2.distfunc(temp);
        d3 = cluster3.distfunc(temp);


        if( (d1<d2) && (d1<d3) )
        {
          cluster1.cluster_data.push_back(temp);
        }
        else if( (d2<d1) && (d2<d3) )
        {
          cluster2.cluster_data.push_back(temp);
        }
        else
        {
          cluster3.cluster_data.push_back(temp);
        }

    }

    cluster::mycluster newcluster1;
    cluster::mycluster newcluster2;
    cluster::mycluster newcluster3;

    float surpressed = cluster1.getmean();
   // std::cout << "surpressed mean : " << surpressed << std::endl;
    float stationary = cluster2.getmean();
   // std::cout << "stationary mean : " << surpressed << std::endl;
    float expressed = cluster3.getmean();
    //std::cout << "expressed mean : " << surpressed << std::endl;

    newcluster1.put_mean(&cluster1.cluster_data);
    float newmean1 = newcluster1.get_newmean();
    std::cout << "New mean value 1: " << newmean1 << std::endl;

    newcluster2.put_mean(&cluster2.cluster_data);
    float newmean2 = newcluster2.get_newmean();
    std::cout << "New mean value 2: " << newmean2 << std::endl;

    newcluster3.put_mean(&cluster3.cluster_data);
    float newmean3 = newcluster3.get_newmean();
    std::cout << "New mean value 3: " << newmean3 << std::endl;

    criteria = abs(surpressed - newmean1) + abs(stationary - newmean2) + abs(expressed - newmean3);
    std::cout << "criteria value: " << criteria << std::endl;

    cluster1.setmean(newmean1);
    cluster2.setmean(newmean2);
    cluster3.setmean(newmean3);

    // std::cout << "New mean value for cluster 1: " << newmean1 << std::endl;
    // std::cout << "New mean value for cluster 2: " << newmean2 << std::endl;
    // std::cout << "New mean value for cluster 3: " << newmean3 << std::endl;

    cluster1.cluster_data.clear();
    cluster2.cluster_data.clear();
    cluster3.cluster_data.clear();

  

  }
  
    return 0;
    
}