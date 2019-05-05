#include "cali.h"
#include <iostream>
#include <map>
#include <TH1F.h>

using namespace std;

int main(){

	char ipfn[124];
	char opfn[124];
	sprintf(ipfn,"ifname.root");//input file
	TFile *ipf=new TFile(ipfn);
	TTree *ipt=(TTree*)ipf->Get("tree");
	if(ipt==0){
	  cout<<"cannot find input tree!"<<endl;
	  return 1;
	}

	sprintf(opfn,"ofname.root");//output file
	TFile *opf=new TFile(opfn,"RECREATE");
	TTree *opt=new TTree("tree","tree");
	cali *sr=new cali(ipt); 
	
        opf->cd();

	sr->Loop(opt);
	opt->Write();
	opf->Close();
        cout<<"Complete"<<endl;	

	return 1;
}
