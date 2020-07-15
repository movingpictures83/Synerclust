#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "SynerClustPlugin.h"

void SynerClustPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
   }
 }
 
void SynerClustPlugin::run() {
   
}

void SynerClustPlugin::output(std::string file) {
 // alpha_diversity.py -i filtered_otu_table.biom -m observed_species,chao1,shannon,PD_whole_tree -t rep_set.tre -o alpha.txt
   std::string command = "export OLDPATH=${PYTHONPATH}; export PYTHONPATH=${PYTHON2_DIST_PACKAGES}:${PYTHON2_SITE_PACKAGES}:${PYTHONPATH}; synerclust.py ";
 command += "-r "+parameters["catalog"]+" ";
 command += "-w "+file+" ";
 command += "-t "+parameters["tree"]+" --run single"+"; cp "+file+"/results/* "+PluginManager::prefix()+"; export PYTHONPATH=OLDPATH";
 std::cout << command << std::endl;

 system(command.c_str());
 
}

PluginProxy<SynerClustPlugin> SynerClustPluginProxy = PluginProxy<SynerClustPlugin>("SynerClust", PluginManager::getInstance());
