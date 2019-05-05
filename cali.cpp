#define cali_cxx
#include "cali.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

using namespace std;

void cali::Loop(TTree *opt)
{
//   In a ROOT session, you can do:
//      Root > .L cali.C
//      Root > cali t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   BranchOpt(opt);
   fChain->SetBranchStatus("*",0);//Open Branchs
   fChain->SetBranchStatus("e",1);
   fChain->SetBranchStatus("ts",1);
   fChain->SetBranchStatus("fr",1);
   fChain->SetBranchStatus("str",1);
   fChain->SetBranchStatus("det",1);
   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if(det==3||det==4) continue;
      de=e;
      dt=ts;
      did=str;
      dfr=fr;
      if(jentry%100000==0) cout<<"Processing..."<<Int_t(Float_t(jentry)/nentries*100)<<" %"<<endl;
     //if(jentry%10000==0) cout<<"Processing..."<<jentry<<endl;
      opt->Fill();
   }
}
//output branchs
void cali::BranchOpt(TTree *opt)
{
  opt->Branch("de",&de,"de/D");
  opt->Branch("dt",&dt,"dt/l");
  opt->Branch("did",&did,"did/I");
  opt->Branch("det",&det,"det/I");
  opt->Branch("dfr",&dfr,"dfr/I");

}
