//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun May  5 08:50:47 2019 by ROOT version 5.34/36
// from TTree tree/tree
// found on file: ../map00335.root
//////////////////////////////////////////////////////////

#ifndef cali_h
#define cali_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class cali {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           det;
   Int_t           fr;
   Int_t           str;
   ULong64_t       ts;
   Double_t        er;
   Double_t        e;
   Int_t           np;
   ULong64_t       tsp[4];   //[np]
   Double_t        eh[4];   //[np]
   Double_t        te[4];   //[np]
   Double_t        rte[4];   //[np]
   Double_t        cate[4];   //[np]
   Double_t        msd[4];   //[np]
   Double_t        flu;
   Double_t        slowfilter[1500];
   Double_t        dwave[750];
   Double_t        twave[750];
   Short_t         rwave[1500];
   Double_t        fd[750];
   Double_t        sd[750];
   Double_t        trap[750];
   Double_t        trap1[750];
   Short_t         dp1[1500];
   Short_t         dp2[1500];
   Int_t           pu;
   Short_t         sample[750];
   Short_t         Sample[1500];
   Double_t        slope;
   Double_t        thr1;
   Double_t        thr2;
   Double_t        min;
   Int_t           bd;
   UChar_t         ch;
   Int_t           nevt;
   Double_t        slopechi2;
   Char_t          st;
   Double_t        eh1[4];   //[np]
   Double_t        bslope;
   //Output branch 
   Double_t        de;
   ULong64_t       dt;
   Int_t           did;
   Int_t           dfr;

   // List of branches
   TBranch        *b_det;   //!
   TBranch        *b_fr;   //!
   TBranch        *b_str;   //!
   TBranch        *b_ts;   //!
   TBranch        *b_er;   //!
   TBranch        *b_e;   //!
   TBranch        *b_np;   //!
   TBranch        *b_tsp;   //!
   TBranch        *b_eh;   //!
   TBranch        *b_te;   //!
   TBranch        *b_rte;   //!
   TBranch        *b_cate;   //!
   TBranch        *b_msd;   //!
   TBranch        *b_flu;   //!
   TBranch        *b_slowfilter;   //!
   TBranch        *b_dwave;   //!
   TBranch        *b_twave;   //!
   TBranch        *b_rwave;   //!
   TBranch        *b_fd;   //!
   TBranch        *b_sd;   //!
   TBranch        *b_trap;   //!
   TBranch        *b_trap1;   //!
   TBranch        *b_dp1;   //!
   TBranch        *b_dp2;   //!
   TBranch        *b_npu;   //!
   TBranch        *b_sample;   //!
   TBranch        *b_Sample;   //!
   TBranch        *b_slope;   //!
   TBranch        *b_thr1;   //!
   TBranch        *b_thr2;   //!
   TBranch        *b_min;   //!
   TBranch        *b_bd;   //!
   TBranch        *b_ch;   //!
   TBranch        *b_nevt;   //!
   TBranch        *b_slopechi2;   //!
   TBranch        *b_st;   //!
   TBranch        *b_eh1;   //!
   TBranch        *b_bslope;   //!

   cali(TTree *tree=0);
   virtual ~cali();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TTree *opt);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual void     BranchOpt(TTree *opt);
};

#endif

#ifdef cali_cxx
cali::cali(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
	return;
   }
   
   Init(tree);
}

cali::~cali()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t cali::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t cali::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void cali::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("det", &det, &b_det);
   fChain->SetBranchAddress("fr", &fr, &b_fr);
   fChain->SetBranchAddress("str", &str, &b_str);
   fChain->SetBranchAddress("ts", &ts, &b_ts);
   fChain->SetBranchAddress("er", &er, &b_er);
   fChain->SetBranchAddress("e", &e, &b_e);
   fChain->SetBranchAddress("np", &np, &b_np);
   fChain->SetBranchAddress("tsp", tsp, &b_tsp);
   fChain->SetBranchAddress("eh", eh, &b_eh);
   fChain->SetBranchAddress("te", te, &b_te);
   fChain->SetBranchAddress("rte", rte, &b_rte);
   fChain->SetBranchAddress("cate", cate, &b_cate);
   fChain->SetBranchAddress("msd", msd, &b_msd);
   fChain->SetBranchAddress("flu", &flu, &b_flu);
   fChain->SetBranchAddress("slowfilter", slowfilter, &b_slowfilter);
   fChain->SetBranchAddress("dwave", dwave, &b_dwave);
   fChain->SetBranchAddress("twave", twave, &b_twave);
   fChain->SetBranchAddress("rwave", rwave, &b_rwave);
   fChain->SetBranchAddress("fd", fd, &b_fd);
   fChain->SetBranchAddress("sd", sd, &b_sd);
   fChain->SetBranchAddress("trap", trap, &b_trap);
   fChain->SetBranchAddress("trap1", trap1, &b_trap1);
   fChain->SetBranchAddress("dp1", dp1, &b_dp1);
   fChain->SetBranchAddress("dp2", dp2, &b_dp2);
   fChain->SetBranchAddress("pu", &pu, &b_npu);
   fChain->SetBranchAddress("sample", sample, &b_sample);
   fChain->SetBranchAddress("Sample", Sample, &b_Sample);
   fChain->SetBranchAddress("slope", &slope, &b_slope);
   fChain->SetBranchAddress("thr1", &thr1, &b_thr1);
   fChain->SetBranchAddress("thr2", &thr2, &b_thr2);
   fChain->SetBranchAddress("min", &min, &b_min);
   fChain->SetBranchAddress("bd", &bd, &b_bd);
   fChain->SetBranchAddress("ch", &ch, &b_ch);
   fChain->SetBranchAddress("nevt", &nevt, &b_nevt);
   fChain->SetBranchAddress("slopechi2", &slopechi2, &b_slopechi2);
   fChain->SetBranchAddress("st", &st, &b_st);
   fChain->SetBranchAddress("eh1", eh1, &b_eh1);
   fChain->SetBranchAddress("bslope", &bslope, &b_bslope);
   Notify();
}

Bool_t cali::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void cali::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t cali::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef cali_cxx
