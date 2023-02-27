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
    float temp, d1, d2, d3, newmean1, newmean2, newmean3, stationary, expressed, surpressed;
    //read in and check if file exitst (WORKS)
    std::string argument1 = argv[1]; //name of log file
    std::vector<float> log_array, indexhold1, indexhold2, indexhold3;
    int indexval = 0;

    
    std::ifstream logfile(argument1);
    if(logfile)
    {
      //std::cout<< "log file exists" << std::endl; ONLY COMMENTED OUT SO IT DIDNT PRINT TO MY SUMMARY FILE

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
    
    //Opening the Gene Name File
    std::ifstream genefile;
    std::string temp1;
    std::vector<std::string> genenames;

    genefile.open("microarray/gene_list.txt");
    if(genefile){
        //std::cout << "gene file exits" << std::endl; ONLY COMMENTED OUT SO IT DIDNT PRINT TO MY SUMMARY FILE
    }
    else
    {
      std::cout << "File does not exist!" << std::endl;
      exit(1);
    }

    //Print file contents to gene_name vector
    while (genefile >> temp1)
    {
        genenames.push_back(temp1);
        
    }


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

    // std::cout << "C1 name: " << cluster1.getname() << std::endl;
    // std::cout << "C1 mean: " << cluster1.getmean() << std::endl;
    // std::cout << "C2 name: " << cluster2.getname() << std::endl;
    // std::cout << "C2 mean: " << cluster2.getmean() << std::endl;
    // std::cout << "C3 name: " << cluster3.getname() << std::endl;
    // std::cout << "C3 mean: " << cluster3.getmean() << std::endl;


    //fore each loop = each points distance to cluster means
    float criteria = 1.0;

    while(criteria > 0.0001){

    cluster1.cluster_data.clear(); //using the clear function 
    cluster2.cluster_data.clear();
    cluster3.cluster_data.clear();



      for(float temp : log_array){ //for each line in the log array...
    
      //calculate distance from means
        d1 = cluster1.distfunc(temp);
        d2 = cluster2.distfunc(temp);
        d3 = cluster3.distfunc(temp);

      //assign datapoints to proper cluster
        if( (d1<d2) && (d1<d3) ) //if d1 is the smallest
        {
          cluster1.cluster_data.push_back(temp);
          indexhold1.push_back(indexval);
        }
        else if( (d2<d1) && (d2<d3) ) // if d2 is the smallest
        {
          cluster2.cluster_data.push_back(temp);
          indexhold2.push_back(indexval);
        }
        else //if d3 is the smallest
        {
          cluster3.cluster_data.push_back(temp);
          indexhold3.push_back(indexval);
        }
        indexval++;
    }
    

    cluster::mycluster newcluster1;
    cluster::mycluster newcluster2;
    cluster::mycluster newcluster3;


    //assigning old means to specific value for criteria measurement
    surpressed = cluster1.getmean();
      //std::cout << "surpressed mean : " << surpressed << std::endl;
    stationary = cluster2.getmean();
      //std::cout << "stationary mean : " << surpressed << std::endl;
    expressed = cluster3.getmean();
      //std::cout << "expressed mean : " << surpressed << std::endl;



    //Assigning new means to the newly made clusters
    newcluster1.put_mean(&cluster1.cluster_data); // set new mean to cluster 1
    newmean1 = newcluster1.get_newmean();
    //std::cout << "New mean value 1: " << newmean1 << std::endl;

    newcluster2.put_mean(&cluster2.cluster_data); // set new mean to cluster 2
    newmean2 = newcluster2.get_newmean();
    //std::cout << "New mean value 2: " << newmean2 << std::endl;

    newcluster3.put_mean(&cluster3.cluster_data); // set new mean to cluster 3
    newmean3 = newcluster3.get_newmean();
    //std::cout << "New mean value 3: " << newmean3 << std::endl;



    //Calculating Criteria
    criteria = abs(surpressed - newmean1) + abs(stationary - newmean2) + abs(expressed - newmean3); // criteria calculation 
    //std::cout << "criteria value: " << criteria << std::endl;

    cluster1.setmean(newmean1); //giving new mean to each cluster
    cluster2.setmean(newmean2);
    cluster3.setmean(newmean3);

    // std::cout << "New mean value for cluster 1: " << newmean1 << std::endl;
    // std::cout << "New mean value for cluster 2: " << newmean2 << std::endl;
    // std::cout << "New mean value for cluster 3: " << newmean3 << std::endl;

    //  std::cout << "Num of suppressed genes: " << cluster1.cluster_data.size() << std::endl;
    //  std::cout << "Num of stationary genes: " << cluster2.cluster_data.size() << std::endl;
    //  std::cout << "Num of expressed genes: " << cluster3.cluster_data.size() << "\n" << std::endl;


    //std::cout << "Num of expressed genes AFTER CLEAR: " << cluster3.cluster_data.size() << std::endl;
    }

    // std::cout << "Final num of supressed genes: " << cluster1.cluster_data.size() << std::endl;
    // std::cout << "Final num of stationary genes: " << cluster2.cluster_data.size() << std::endl;
    // std::cout << "Final num of expressed genes: " << cluster3.cluster_data.size() << std::endl;

    // std::cout << "New mean value for cluster 1: " << cluster1.getmean() << std::endl;
    // std::cout << "New mean value for cluster 2: " << cluster2.getmean() << std::endl;
    // std::cout << "New mean value for cluster 3: " << cluster3.getmean()<< std::endl;
   
  

    //Opening files to write clusters to
    std::ofstream SupressedFile;
    std::ofstream StationaryFile;
    std::ofstream ExpressedFile;


    SupressedFile.open ("surpressed_genes.txt");
    StationaryFile.open ("stationary_genes.txt");
    ExpressedFile.open ("expressed_genes.txt");

    int indexval1 = 0;

    //******* does exactly what I did above, but since the distances are already calculated, doing it again should allow for nothing to change and the names to be assigned
    for(float temp : log_array){ //doing this to get the size

      d1 = cluster1.distfunc(temp);
      d2 = cluster2.distfunc(temp);
      d3 = cluster3.distfunc(temp);

        if ( (d1<d2) && (d1<d3) )
        {
          SupressedFile << genenames[indexval1] << std::endl;
        }

        else if ( (d2<d1) && (d2<d3) )
        {
         StationaryFile << genenames[indexval1] << std::endl;
        }

        else
        {
          ExpressedFile << genenames[indexval1] << std::endl;
        }
    indexval1++;
    }

  //used to print into my summary file
    std::cout << "Final Number of Suppressed Genes: " << cluster1.cluster_data.size() << std::endl;
    std::cout << "Final Number of Stationary Genes: " << cluster2.cluster_data.size() << std::endl;
    std::cout << "Final Number of Expressed Genes: " << cluster3.cluster_data.size() << std::endl;

    std::cout << "Final Suppressed Gene Cluster Mean: " << cluster1.getmean() << std::endl;
    std::cout << "Final Stationary Gene Cluster Mean: " << cluster2.getmean() << std::endl;
    std::cout << "Final Expressed Gene Cluster Mean: " << cluster3.getmean() << '\n' <<  std::endl;

    



    SupressedFile.close();
    StationaryFile.close();
    ExpressedFile.close();


  
    return 0;
    
}