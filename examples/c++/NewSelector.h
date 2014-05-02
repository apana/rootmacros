//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Apr 17 16:55:17 2006 by ROOT version 5.06/00
// from TTree Events/Events
// found on file: ../rootfiles/tower_jet_pool_howt_3.0.root
//////////////////////////////////////////////////////////

#ifndef NewSelector_h
#define NewSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
   const Int_t kMaxprocess_history = 1;
   const Int_t kMaxid__run = 1;
   const Int_t kMaxid__event = 1;
   const Int_t kMaxtime__timeLow = 1;
   const Int_t kMaxtime__timeHigh = 1;
   const Int_t kMaxCaloJet_mcone5 = 1;
   const Int_t kMaxCaloJet_mcone5_obj = 2;
   const Int_t kMaxCaloJet_mcone7 = 1;
   const Int_t kMaxCaloJet_mcone7_obj = 1;
   const Int_t kMaxCaloTower_towermaker = 1;
   const Int_t kMaxCaloTower_towermaker_obj_obj = 84;
   const Int_t kMaxCaloTower_towermaker_obj_obj_id__id = 84;
   const Int_t kMaxFEDRawDataCollection_HcalTBSource = 1;
   const Int_t kMaxFEDRawDataCollection_HcalTBSource_obj_data_ = 2048;
   const Int_t kMaxFEDRawDataCollection_HcalTBSource_obj_data__data = 2048;
   const Int_t kMaxHBHEDataFrame_unpacker = 1;
   const Int_t kMaxHBHEDataFrame_unpacker_obj_obj = 72;
   const Int_t kMaxHBHEDataFrame_unpacker_obj_obj_id__id = 72;
   const Int_t kMaxHBHEDataFrame_unpacker_obj_obj_electronicsId__hcalElectronicsId = 72;
   const Int_t kMaxHBHEDataFrame_unpacker_obj_obj_size = 72;
   const Int_t kMaxHBHEDataFrame_unpacker_obj_obj_hcalPresamples = 72;
   const Int_t kMaxHBHEDataFrame_unpacker_obj_obj_data = 72;
   const Int_t kMaxHBHERecHit_reco_hbhe = 1;
   const Int_t kMaxHBHERecHit_reco_hbhe_obj_obj = 72;
   const Int_t kMaxHBHERecHit_reco_hbhe_obj_obj_id__id = 72;
   const Int_t kMaxHBHERecHit_reco_hbhe_obj_obj_energy = 72;
   const Int_t kMaxHBHERecHit_reco_hbhe_obj_obj_time = 72;
   const Int_t kMaxHFDataFrame_unpacker = 1;
   const Int_t kMaxHFDataFrame_unpacker_obj_obj = 1;
   const Int_t kMaxHFDataFrame_unpacker_obj_obj_id__id = 1;
   const Int_t kMaxHFDataFrame_unpacker_obj_obj_electronicsId__hcalElectronicsId = 1;
   const Int_t kMaxHFDataFrame_unpacker_obj_obj_size = 1;
   const Int_t kMaxHFDataFrame_unpacker_obj_obj_hcalPresamples = 1;
   const Int_t kMaxHFDataFrame_unpacker_obj_obj_data = 1;
   const Int_t kMaxHFRecHit_reco_hf = 1;
   const Int_t kMaxHFRecHit_reco_hf_obj_obj = 1;
   const Int_t kMaxHFRecHit_reco_hf_obj_obj_id__id = 1;
   const Int_t kMaxHFRecHit_reco_hf_obj_obj_energy = 1;
   const Int_t kMaxHFRecHit_reco_hf_obj_obj_time = 1;
   const Int_t kMaxHODataFrame_unpacker = 1;
   const Int_t kMaxHODataFrame_unpacker_obj_obj = 45;
   const Int_t kMaxHODataFrame_unpacker_obj_obj_id__id = 45;
   const Int_t kMaxHODataFrame_unpacker_obj_obj_electronicsId__hcalElectronicsId = 45;
   const Int_t kMaxHODataFrame_unpacker_obj_obj_size = 45;
   const Int_t kMaxHODataFrame_unpacker_obj_obj_hcalPresamples = 45;
   const Int_t kMaxHODataFrame_unpacker_obj_obj_data = 45;
   const Int_t kMaxHORecHit_reco_ho = 1;
   const Int_t kMaxHORecHit_reco_ho_obj_obj = 45;
   const Int_t kMaxHORecHit_reco_ho_obj_obj_id__id = 45;
   const Int_t kMaxHORecHit_reco_ho_obj_obj_energy = 45;
   const Int_t kMaxHORecHit_reco_ho_obj_obj_time = 45;
   const Int_t kMaxHcalTBEventPosition_tbunpacker = 1;
   const Int_t kMaxHcalTBEventPosition_tbunpacker_obj_hfTableX = 1;
   const Int_t kMaxHcalTBEventPosition_tbunpacker_obj_hfTableY = 1;
   const Int_t kMaxHcalTBEventPosition_tbunpacker_obj_hfTableV = 1;
   const Int_t kMaxHcalTBEventPosition_tbunpacker_obj_hbheTableEta = 1;
   const Int_t kMaxHcalTBEventPosition_tbunpacker_obj_hbheTablePhi = 1;
   const Int_t kMaxHcalTBEventPosition_tbunpacker_obj_ax = 1;
   const Int_t kMaxHcalTBEventPosition_tbunpacker_obj_ay = 1;
   const Int_t kMaxHcalTBEventPosition_tbunpacker_obj_bx = 1;
   const Int_t kMaxHcalTBEventPosition_tbunpacker_obj_by = 1;
   const Int_t kMaxHcalTBEventPosition_tbunpacker_obj_cx = 1;
   const Int_t kMaxHcalTBEventPosition_tbunpacker_obj_cy = 1;
   const Int_t kMaxHcalTBEventPosition_tbunpacker_obj_dx = 1;
   const Int_t kMaxHcalTBEventPosition_tbunpacker_obj_dy = 1;
   const Int_t kMaxHcalTBEventPosition_tbunpacker_obj_ex = 1;
   const Int_t kMaxHcalTBEventPosition_tbunpacker_obj_ey = 1;
   const Int_t kMaxHcalTBRunData_tbunpacker = 1;
   const Int_t kMaxHcalTBRunData_tbunpacker_obj_runType = 1;
   const Int_t kMaxHcalTBRunData_tbunpacker_obj_beamMode = 1;
   const Int_t kMaxHcalTBRunData_tbunpacker_obj_beamEnergyGeV = 1;
   const Int_t kMaxHcalTBTiming_tbunpacker = 1;
   const Int_t kMaxHcalTBTiming_tbunpacker_obj_triggerTime = 1;
   const Int_t kMaxHcalTBTiming_tbunpacker_obj_ttcL1Atime = 1;
   const Int_t kMaxHcalTBTiming_tbunpacker_obj_beamCoincidence = 1;
   const Int_t kMaxHcalTBTiming_tbunpacker_obj_laserFlash = 1;
   const Int_t kMaxHcalTBTiming_tbunpacker_obj_qiePhase = 1;
   const Int_t kMaxHcalTBTiming_tbunpacker_obj_m1hits = 1;
   const Int_t kMaxHcalTBTiming_tbunpacker_obj_m2hits = 1;
   const Int_t kMaxHcalTBTiming_tbunpacker_obj_m3hits = 1;
   const Int_t kMaxHcalTBTiming_tbunpacker_obj_s1hits = 1;
   const Int_t kMaxHcalTBTiming_tbunpacker_obj_s2hits = 1;
   const Int_t kMaxHcalTBTiming_tbunpacker_obj_s3hits = 1;
   const Int_t kMaxHcalTBTiming_tbunpacker_obj_s4hits = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_runNumberSequenceId = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_runNumber = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_triggerWord = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_triggerTimeUsec = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_triggerTimeBase = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_spillNumber = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_orbitNumber = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_bunchNumber = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_eventNumber = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_flagsDaqTtype = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_algoBits3 = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_algoBits2 = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_algoBits1 = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_algoBits0 = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_techBits = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_gps1234 = 1;
   const Int_t kMaxHcalTBTriggerData_tbunpacker_obj_gps5678 = 1;
   const Int_t kMaxHcalTriggerPrimitiveDigi_unpacker = 1;
   const Int_t kMaxHcalTriggerPrimitiveDigi_unpacker_obj_obj = 1;
   const Int_t kMaxHcalTriggerPrimitiveDigi_unpacker_obj_obj_id__id = 1;
   const Int_t kMaxHcalTriggerPrimitiveDigi_unpacker_obj_obj_size = 1;
   const Int_t kMaxHcalTriggerPrimitiveDigi_unpacker_obj_obj_hcalPresamples = 1;
   const Int_t kMaxHcalTriggerPrimitiveDigi_unpacker_obj_obj_data = 1;
   const Int_t kMaxdata_ = 15;
   const Int_t kMaxdata__productID__id = 15;

class NewSelector : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leave types
 //edm::EventAux   *EventAux;
   vector<string>  process_history_;
   ULong_t         id__run_;
   ULong_t         id__event_;
   ULong_t         time__timeLow_;
   ULong_t         time__timeHigh_;
 //edm::Wrapper<vector<CaloJet> > *CaloJet_mcone5.;
   Bool_t          CaloJet_mcone5_present;
   Int_t           CaloJet_mcone5_obj_;
   Double_t        CaloJet_mcone5_obj_data_px[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   Double_t        CaloJet_mcone5_obj_data_py[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   Double_t        CaloJet_mcone5_obj_data_pz[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   Double_t        CaloJet_mcone5_obj_data_e[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   Double_t        CaloJet_mcone5_obj_data_p[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   Double_t        CaloJet_mcone5_obj_data_pt[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   Double_t        CaloJet_mcone5_obj_data_et[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   Double_t        CaloJet_mcone5_obj_data_m[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   Double_t        CaloJet_mcone5_obj_data_phi[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   Double_t        CaloJet_mcone5_obj_data_eta[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   Double_t        CaloJet_mcone5_obj_data_y[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   Int_t           CaloJet_mcone5_obj_data_numberOfConstituents[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   vector<CaloTowerDetId> CaloJet_mcone5_obj_m_towerIdxs[kMaxCaloJet_mcone5_obj];
   Double_t        CaloJet_mcone5_obj_m_maxEInEmTowers[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   Double_t        CaloJet_mcone5_obj_m_maxEInHadTowers[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   Double_t        CaloJet_mcone5_obj_m_energyFractionInHCAL[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   Double_t        CaloJet_mcone5_obj_m_energyFractionInECAL[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
   Int_t           CaloJet_mcone5_obj_m_n90[kMaxCaloJet_mcone5_obj];   //[CaloJet_mcone5.obj_]
 //edm::Wrapper<vector<CaloJet> > *CaloJet_mcone7.;
   Bool_t          CaloJet_mcone7_present;
   Int_t           CaloJet_mcone7_obj_;
   Double_t        CaloJet_mcone7_obj_data_px[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   Double_t        CaloJet_mcone7_obj_data_py[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   Double_t        CaloJet_mcone7_obj_data_pz[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   Double_t        CaloJet_mcone7_obj_data_e[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   Double_t        CaloJet_mcone7_obj_data_p[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   Double_t        CaloJet_mcone7_obj_data_pt[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   Double_t        CaloJet_mcone7_obj_data_et[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   Double_t        CaloJet_mcone7_obj_data_m[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   Double_t        CaloJet_mcone7_obj_data_phi[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   Double_t        CaloJet_mcone7_obj_data_eta[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   Double_t        CaloJet_mcone7_obj_data_y[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   Int_t           CaloJet_mcone7_obj_data_numberOfConstituents[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   vector<CaloTowerDetId> CaloJet_mcone7_obj_m_towerIdxs[kMaxCaloJet_mcone7_obj];
   Double_t        CaloJet_mcone7_obj_m_maxEInEmTowers[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   Double_t        CaloJet_mcone7_obj_m_maxEInHadTowers[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   Double_t        CaloJet_mcone7_obj_m_energyFractionInHCAL[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   Double_t        CaloJet_mcone7_obj_m_energyFractionInECAL[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
   Int_t           CaloJet_mcone7_obj_m_n90[kMaxCaloJet_mcone7_obj];   //[CaloJet_mcone7.obj_]
 //edm::Wrapper<edm::SortedCollection<CaloTower,edm::StrictWeakOrdering<CaloTower> > > *CaloTower_towermaker.;
   Bool_t          CaloTower_towermaker_present;
   Int_t           CaloTower_towermaker_obj_obj_;
   UInt_t          CaloTower_towermaker_obj_obj_id__id_[kMaxCaloTower_towermaker_obj_obj];   //[CaloTower_towermaker.obj.obj_]
   Double_t        CaloTower_towermaker_obj_obj_eT[kMaxCaloTower_towermaker_obj_obj];   //[CaloTower_towermaker.obj.obj_]
   Double_t        CaloTower_towermaker_obj_obj_eT_em[kMaxCaloTower_towermaker_obj_obj];   //[CaloTower_towermaker.obj.obj_]
   Double_t        CaloTower_towermaker_obj_obj_eT_had[kMaxCaloTower_towermaker_obj_obj];   //[CaloTower_towermaker.obj.obj_]
   Double_t        CaloTower_towermaker_obj_obj_eT_outer[kMaxCaloTower_towermaker_obj_obj];   //[CaloTower_towermaker.obj.obj_]
   Double_t        CaloTower_towermaker_obj_obj_eta[kMaxCaloTower_towermaker_obj_obj];   //[CaloTower_towermaker.obj.obj_]
   Double_t        CaloTower_towermaker_obj_obj_phi[kMaxCaloTower_towermaker_obj_obj];   //[CaloTower_towermaker.obj.obj_]
   vector<DetId>   CaloTower_towermaker_obj_obj_constituents[kMaxCaloTower_towermaker_obj_obj];
 //edm::Wrapper<FEDRawDataCollection> *FEDRawDataCollection_HcalTBSource.;
   Bool_t          FEDRawDataCollection_HcalTBSource_present;
   Int_t           FEDRawDataCollection_HcalTBSource_obj_data__;
   vector<unsigned char> FEDRawDataCollection_HcalTBSource_obj_data__data_[kMaxFEDRawDataCollection_HcalTBSource_obj_data_];
 //edm::Wrapper<edm::SortedCollection<HBHEDataFrame,edm::StrictWeakOrdering<HBHEDataFrame> > > *HBHEDataFrame_unpacker.;
   Bool_t          HBHEDataFrame_unpacker_present;
   Int_t           HBHEDataFrame_unpacker_obj_obj_;
   UInt_t          HBHEDataFrame_unpacker_obj_obj_id__id_[kMaxHBHEDataFrame_unpacker_obj_obj];   //[HBHEDataFrame_unpacker.obj.obj_]
   UInt_t          HBHEDataFrame_unpacker_obj_obj_electronicsId__hcalElectronicsId_[kMaxHBHEDataFrame_unpacker_obj_obj];   //[HBHEDataFrame_unpacker.obj.obj_]
   Int_t           HBHEDataFrame_unpacker_obj_obj_size_[kMaxHBHEDataFrame_unpacker_obj_obj];   //[HBHEDataFrame_unpacker.obj.obj_]
   Int_t           HBHEDataFrame_unpacker_obj_obj_hcalPresamples_[kMaxHBHEDataFrame_unpacker_obj_obj];   //[HBHEDataFrame_unpacker.obj.obj_]
   vector<HcalQIESample> HBHEDataFrame_unpacker_obj_obj_data_[kMaxHBHEDataFrame_unpacker_obj_obj];
 //edm::Wrapper<edm::SortedCollection<HBHERecHit,edm::StrictWeakOrdering<HBHERecHit> > > *HBHERecHit_reco_hbhe.;
   Bool_t          HBHERecHit_reco_hbhe_present;
   Int_t           HBHERecHit_reco_hbhe_obj_obj_;
   UInt_t          HBHERecHit_reco_hbhe_obj_obj_id__id_[kMaxHBHERecHit_reco_hbhe_obj_obj];   //[HBHERecHit_reco_hbhe.obj.obj_]
   Float_t         HBHERecHit_reco_hbhe_obj_obj_energy_[kMaxHBHERecHit_reco_hbhe_obj_obj];   //[HBHERecHit_reco_hbhe.obj.obj_]
   Float_t         HBHERecHit_reco_hbhe_obj_obj_time_[kMaxHBHERecHit_reco_hbhe_obj_obj];   //[HBHERecHit_reco_hbhe.obj.obj_]
 //edm::Wrapper<edm::SortedCollection<HFDataFrame,edm::StrictWeakOrdering<HFDataFrame> > > *HFDataFrame_unpacker.;
   Bool_t          HFDataFrame_unpacker_present;
   Int_t           HFDataFrame_unpacker_obj_obj_;
   UInt_t          HFDataFrame_unpacker_obj_obj_id__id_[kMaxHFDataFrame_unpacker_obj_obj];   //[HFDataFrame_unpacker.obj.obj_]
   UInt_t          HFDataFrame_unpacker_obj_obj_electronicsId__hcalElectronicsId_[kMaxHFDataFrame_unpacker_obj_obj];   //[HFDataFrame_unpacker.obj.obj_]
   Int_t           HFDataFrame_unpacker_obj_obj_size_[kMaxHFDataFrame_unpacker_obj_obj];   //[HFDataFrame_unpacker.obj.obj_]
   Int_t           HFDataFrame_unpacker_obj_obj_hcalPresamples_[kMaxHFDataFrame_unpacker_obj_obj];   //[HFDataFrame_unpacker.obj.obj_]
   vector<HcalQIESample> HFDataFrame_unpacker_obj_obj_data_[kMaxHFDataFrame_unpacker_obj_obj];
 //edm::Wrapper<edm::SortedCollection<HFRecHit,edm::StrictWeakOrdering<HFRecHit> > > *HFRecHit_reco_hf.;
   Bool_t          HFRecHit_reco_hf_present;
   Int_t           HFRecHit_reco_hf_obj_obj_;
   UInt_t          HFRecHit_reco_hf_obj_obj_id__id_[kMaxHFRecHit_reco_hf_obj_obj];   //[HFRecHit_reco_hf.obj.obj_]
   Float_t         HFRecHit_reco_hf_obj_obj_energy_[kMaxHFRecHit_reco_hf_obj_obj];   //[HFRecHit_reco_hf.obj.obj_]
   Float_t         HFRecHit_reco_hf_obj_obj_time_[kMaxHFRecHit_reco_hf_obj_obj];   //[HFRecHit_reco_hf.obj.obj_]
 //edm::Wrapper<edm::SortedCollection<HODataFrame,edm::StrictWeakOrdering<HODataFrame> > > *HODataFrame_unpacker.;
   Bool_t          HODataFrame_unpacker_present;
   Int_t           HODataFrame_unpacker_obj_obj_;
   UInt_t          HODataFrame_unpacker_obj_obj_id__id_[kMaxHODataFrame_unpacker_obj_obj];   //[HODataFrame_unpacker.obj.obj_]
   UInt_t          HODataFrame_unpacker_obj_obj_electronicsId__hcalElectronicsId_[kMaxHODataFrame_unpacker_obj_obj];   //[HODataFrame_unpacker.obj.obj_]
   Int_t           HODataFrame_unpacker_obj_obj_size_[kMaxHODataFrame_unpacker_obj_obj];   //[HODataFrame_unpacker.obj.obj_]
   Int_t           HODataFrame_unpacker_obj_obj_hcalPresamples_[kMaxHODataFrame_unpacker_obj_obj];   //[HODataFrame_unpacker.obj.obj_]
   vector<HcalQIESample> HODataFrame_unpacker_obj_obj_data_[kMaxHODataFrame_unpacker_obj_obj];
 //edm::Wrapper<edm::SortedCollection<HORecHit,edm::StrictWeakOrdering<HORecHit> > > *HORecHit_reco_ho.;
   Bool_t          HORecHit_reco_ho_present;
   Int_t           HORecHit_reco_ho_obj_obj_;
   UInt_t          HORecHit_reco_ho_obj_obj_id__id_[kMaxHORecHit_reco_ho_obj_obj];   //[HORecHit_reco_ho.obj.obj_]
   Float_t         HORecHit_reco_ho_obj_obj_energy_[kMaxHORecHit_reco_ho_obj_obj];   //[HORecHit_reco_ho.obj.obj_]
   Float_t         HORecHit_reco_ho_obj_obj_time_[kMaxHORecHit_reco_ho_obj_obj];   //[HORecHit_reco_ho.obj.obj_]
 //edm::Wrapper<HcalTBEventPosition> *HcalTBEventPosition_tbunpacker.;
   Bool_t          HcalTBEventPosition_tbunpacker_present;
   Double_t        HcalTBEventPosition_tbunpacker_obj_hfTableX_;
   Double_t        HcalTBEventPosition_tbunpacker_obj_hfTableY_;
   Double_t        HcalTBEventPosition_tbunpacker_obj_hfTableV_;
   Double_t        HcalTBEventPosition_tbunpacker_obj_hbheTableEta_;
   Double_t        HcalTBEventPosition_tbunpacker_obj_hbheTablePhi_;
   vector<double>  HcalTBEventPosition_tbunpacker_obj_ax_;
   vector<double>  HcalTBEventPosition_tbunpacker_obj_ay_;
   vector<double>  HcalTBEventPosition_tbunpacker_obj_bx_;
   vector<double>  HcalTBEventPosition_tbunpacker_obj_by_;
   vector<double>  HcalTBEventPosition_tbunpacker_obj_cx_;
   vector<double>  HcalTBEventPosition_tbunpacker_obj_cy_;
   vector<double>  HcalTBEventPosition_tbunpacker_obj_dx_;
   vector<double>  HcalTBEventPosition_tbunpacker_obj_dy_;
   vector<double>  HcalTBEventPosition_tbunpacker_obj_ex_;
   vector<double>  HcalTBEventPosition_tbunpacker_obj_ey_;
 //edm::Wrapper<HcalTBRunData> *HcalTBRunData_tbunpacker.;
   Bool_t          HcalTBRunData_tbunpacker_present;
   string          HcalTBRunData_tbunpacker_obj_runType_;
   string          HcalTBRunData_tbunpacker_obj_beamMode_;
   Double_t        HcalTBRunData_tbunpacker_obj_beamEnergyGeV_;
 //edm::Wrapper<HcalTBTiming> *HcalTBTiming_tbunpacker.;
   Bool_t          HcalTBTiming_tbunpacker_present;
   Double_t        HcalTBTiming_tbunpacker_obj_triggerTime_;
   Double_t        HcalTBTiming_tbunpacker_obj_ttcL1Atime_;
   Double_t        HcalTBTiming_tbunpacker_obj_beamCoincidence_;
   Double_t        HcalTBTiming_tbunpacker_obj_laserFlash_;
   Double_t        HcalTBTiming_tbunpacker_obj_qiePhase_;
   vector<double>  HcalTBTiming_tbunpacker_obj_m1hits_;
   vector<double>  HcalTBTiming_tbunpacker_obj_m2hits_;
   vector<double>  HcalTBTiming_tbunpacker_obj_m3hits_;
   vector<double>  HcalTBTiming_tbunpacker_obj_s1hits_;
   vector<double>  HcalTBTiming_tbunpacker_obj_s2hits_;
   vector<double>  HcalTBTiming_tbunpacker_obj_s3hits_;
   vector<double>  HcalTBTiming_tbunpacker_obj_s4hits_;
 //edm::Wrapper<HcalTBTriggerData> *HcalTBTriggerData_tbunpacker.;
   Bool_t          HcalTBTriggerData_tbunpacker_present;
   string          HcalTBTriggerData_tbunpacker_obj_runNumberSequenceId_;
   UInt_t          HcalTBTriggerData_tbunpacker_obj_runNumber_;
   UInt_t          HcalTBTriggerData_tbunpacker_obj_triggerWord_;
   UInt_t          HcalTBTriggerData_tbunpacker_obj_triggerTimeUsec_;
   UInt_t          HcalTBTriggerData_tbunpacker_obj_triggerTimeBase_;
   UInt_t          HcalTBTriggerData_tbunpacker_obj_spillNumber_;
   UInt_t          HcalTBTriggerData_tbunpacker_obj_orbitNumber_;
   UShort_t        HcalTBTriggerData_tbunpacker_obj_bunchNumber_;
   UInt_t          HcalTBTriggerData_tbunpacker_obj_eventNumber_;
   UInt_t          HcalTBTriggerData_tbunpacker_obj_flagsDaqTtype_;
   UInt_t          HcalTBTriggerData_tbunpacker_obj_algoBits3_;
   UInt_t          HcalTBTriggerData_tbunpacker_obj_algoBits2_;
   UInt_t          HcalTBTriggerData_tbunpacker_obj_algoBits1_;
   UInt_t          HcalTBTriggerData_tbunpacker_obj_algoBits0_;
   UInt_t          HcalTBTriggerData_tbunpacker_obj_techBits_;
   UInt_t          HcalTBTriggerData_tbunpacker_obj_gps1234_;
   UInt_t          HcalTBTriggerData_tbunpacker_obj_gps5678_;
 //edm::Wrapper<edm::SortedCollection<HcalTriggerPrimitiveDigi,edm::StrictWeakOrdering<HcalTriggerPrimitiveDigi> > > *HcalTriggerPrimitiveDigi_unpacker.;
   Bool_t          HcalTriggerPrimitiveDigi_unpacker_present;
   Int_t           HcalTriggerPrimitiveDigi_unpacker_obj_obj_;
   UInt_t          HcalTriggerPrimitiveDigi_unpacker_obj_obj_id__id_[kMaxHcalTriggerPrimitiveDigi_unpacker_obj_obj];   //[HcalTriggerPrimitiveDigi_unpacker.obj.obj_]
   Int_t           HcalTriggerPrimitiveDigi_unpacker_obj_obj_size_[kMaxHcalTriggerPrimitiveDigi_unpacker_obj_obj];   //[HcalTriggerPrimitiveDigi_unpacker.obj.obj_]
   Int_t           HcalTriggerPrimitiveDigi_unpacker_obj_obj_hcalPresamples_[kMaxHcalTriggerPrimitiveDigi_unpacker_obj_obj];   //[HcalTriggerPrimitiveDigi_unpacker.obj.obj_]
   vector<HcalTriggerPrimitiveSample> HcalTriggerPrimitiveDigi_unpacker_obj_obj_data_[kMaxHcalTriggerPrimitiveDigi_unpacker_obj_obj];
 //edm::EventProvenance *Provenance;
   Int_t           data__;
   ULong_t         data__productID__id_[kMaxdata_];   //[data__]
   vector<edm::ProductID> data__parents[kMaxdata_];
   ULong_t         data__cid[kMaxdata_];   //[data__]
   Long_t          data__status[kMaxdata_];   //[data__]

   // List of branches
   TBranch        *b_EventAux_process_history_;   //!
   TBranch        *b_EventAux_id__run_;   //!
   TBranch        *b_EventAux_id__event_;   //!
   TBranch        *b_EventAux_time__timeLow_;   //!
   TBranch        *b_EventAux_time__timeHigh_;   //!
   TBranch        *b_CaloJet_mcone5_present;   //!
   TBranch        *b_CaloJet_mcone5_obj_;   //!
   TBranch        *b_CaloJet_mcone5_obj_data_px;   //!
   TBranch        *b_CaloJet_mcone5_obj_data_py;   //!
   TBranch        *b_CaloJet_mcone5_obj_data_pz;   //!
   TBranch        *b_CaloJet_mcone5_obj_data_e;   //!
   TBranch        *b_CaloJet_mcone5_obj_data_p;   //!
   TBranch        *b_CaloJet_mcone5_obj_data_pt;   //!
   TBranch        *b_CaloJet_mcone5_obj_data_et;   //!
   TBranch        *b_CaloJet_mcone5_obj_data_m;   //!
   TBranch        *b_CaloJet_mcone5_obj_data_phi;   //!
   TBranch        *b_CaloJet_mcone5_obj_data_eta;   //!
   TBranch        *b_CaloJet_mcone5_obj_data_y;   //!
   TBranch        *b_CaloJet_mcone5_obj_data_numberOfConstituents;   //!
   TBranch        *b_CaloJet_mcone5_obj_m_towerIdxs;   //!
   TBranch        *b_CaloJet_mcone5_obj_m_maxEInEmTowers;   //!
   TBranch        *b_CaloJet_mcone5_obj_m_maxEInHadTowers;   //!
   TBranch        *b_CaloJet_mcone5_obj_m_energyFractionInHCAL;   //!
   TBranch        *b_CaloJet_mcone5_obj_m_energyFractionInECAL;   //!
   TBranch        *b_CaloJet_mcone5_obj_m_n90;   //!
   TBranch        *b_CaloJet_mcone7_present;   //!
   TBranch        *b_CaloJet_mcone7_obj_;   //!
   TBranch        *b_CaloJet_mcone7_obj_data_px;   //!
   TBranch        *b_CaloJet_mcone7_obj_data_py;   //!
   TBranch        *b_CaloJet_mcone7_obj_data_pz;   //!
   TBranch        *b_CaloJet_mcone7_obj_data_e;   //!
   TBranch        *b_CaloJet_mcone7_obj_data_p;   //!
   TBranch        *b_CaloJet_mcone7_obj_data_pt;   //!
   TBranch        *b_CaloJet_mcone7_obj_data_et;   //!
   TBranch        *b_CaloJet_mcone7_obj_data_m;   //!
   TBranch        *b_CaloJet_mcone7_obj_data_phi;   //!
   TBranch        *b_CaloJet_mcone7_obj_data_eta;   //!
   TBranch        *b_CaloJet_mcone7_obj_data_y;   //!
   TBranch        *b_CaloJet_mcone7_obj_data_numberOfConstituents;   //!
   TBranch        *b_CaloJet_mcone7_obj_m_towerIdxs;   //!
   TBranch        *b_CaloJet_mcone7_obj_m_maxEInEmTowers;   //!
   TBranch        *b_CaloJet_mcone7_obj_m_maxEInHadTowers;   //!
   TBranch        *b_CaloJet_mcone7_obj_m_energyFractionInHCAL;   //!
   TBranch        *b_CaloJet_mcone7_obj_m_energyFractionInECAL;   //!
   TBranch        *b_CaloJet_mcone7_obj_m_n90;   //!
   TBranch        *b_CaloTower_towermaker_present;   //!
   TBranch        *b_CaloTower_towermaker_obj_obj_;   //!
   TBranch        *b_CaloTower_towermaker_obj_obj_id__id_;   //!
   TBranch        *b_CaloTower_towermaker_obj_obj_eT;   //!
   TBranch        *b_CaloTower_towermaker_obj_obj_eT_em;   //!
   TBranch        *b_CaloTower_towermaker_obj_obj_eT_had;   //!
   TBranch        *b_CaloTower_towermaker_obj_obj_eT_outer;   //!
   TBranch        *b_CaloTower_towermaker_obj_obj_eta;   //!
   TBranch        *b_CaloTower_towermaker_obj_obj_phi;   //!
   TBranch        *b_CaloTower_towermaker_obj_obj_constituents;   //!
   TBranch        *b_FEDRawDataCollection_HcalTBSource_present;   //!
   TBranch        *b_FEDRawDataCollection_HcalTBSource_obj_data__;   //!
   TBranch        *b_FEDRawDataCollection_HcalTBSource_obj_data__data_;   //!
   TBranch        *b_HBHEDataFrame_unpacker_present;   //!
   TBranch        *b_HBHEDataFrame_unpacker_obj_obj_;   //!
   TBranch        *b_HBHEDataFrame_unpacker_obj_obj_id__id_;   //!
   TBranch        *b_HBHEDataFrame_unpacker_obj_obj_electronicsId__hcalElectronicsId_;   //!
   TBranch        *b_HBHEDataFrame_unpacker_obj_obj_size_;   //!
   TBranch        *b_HBHEDataFrame_unpacker_obj_obj_hcalPresamples_;   //!
   TBranch        *b_HBHEDataFrame_unpacker_obj_obj_data_;   //!
   TBranch        *b_HBHERecHit_reco_hbhe_present;   //!
   TBranch        *b_HBHERecHit_reco_hbhe_obj_obj_;   //!
   TBranch        *b_HBHERecHit_reco_hbhe_obj_obj_id__id_;   //!
   TBranch        *b_HBHERecHit_reco_hbhe_obj_obj_energy_;   //!
   TBranch        *b_HBHERecHit_reco_hbhe_obj_obj_time_;   //!
   TBranch        *b_HFDataFrame_unpacker_present;   //!
   TBranch        *b_HFDataFrame_unpacker_obj_obj_;   //!
   TBranch        *b_HFDataFrame_unpacker_obj_obj_id__id_;   //!
   TBranch        *b_HFDataFrame_unpacker_obj_obj_electronicsId__hcalElectronicsId_;   //!
   TBranch        *b_HFDataFrame_unpacker_obj_obj_size_;   //!
   TBranch        *b_HFDataFrame_unpacker_obj_obj_hcalPresamples_;   //!
   TBranch        *b_HFDataFrame_unpacker_obj_obj_data_;   //!
   TBranch        *b_HFRecHit_reco_hf_present;   //!
   TBranch        *b_HFRecHit_reco_hf_obj_obj_;   //!
   TBranch        *b_HFRecHit_reco_hf_obj_obj_id__id_;   //!
   TBranch        *b_HFRecHit_reco_hf_obj_obj_energy_;   //!
   TBranch        *b_HFRecHit_reco_hf_obj_obj_time_;   //!
   TBranch        *b_HODataFrame_unpacker_present;   //!
   TBranch        *b_HODataFrame_unpacker_obj_obj_;   //!
   TBranch        *b_HODataFrame_unpacker_obj_obj_id__id_;   //!
   TBranch        *b_HODataFrame_unpacker_obj_obj_electronicsId__hcalElectronicsId_;   //!
   TBranch        *b_HODataFrame_unpacker_obj_obj_size_;   //!
   TBranch        *b_HODataFrame_unpacker_obj_obj_hcalPresamples_;   //!
   TBranch        *b_HODataFrame_unpacker_obj_obj_data_;   //!
   TBranch        *b_HORecHit_reco_ho_present;   //!
   TBranch        *b_HORecHit_reco_ho_obj_obj_;   //!
   TBranch        *b_HORecHit_reco_ho_obj_obj_id__id_;   //!
   TBranch        *b_HORecHit_reco_ho_obj_obj_energy_;   //!
   TBranch        *b_HORecHit_reco_ho_obj_obj_time_;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_present;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_obj_hfTableX_;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_obj_hfTableY_;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_obj_hfTableV_;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_obj_hbheTableEta_;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_obj_hbheTablePhi_;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_obj_ax_;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_obj_ay_;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_obj_bx_;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_obj_by_;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_obj_cx_;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_obj_cy_;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_obj_dx_;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_obj_dy_;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_obj_ex_;   //!
   TBranch        *b_HcalTBEventPosition_tbunpacker_obj_ey_;   //!
   TBranch        *b_HcalTBRunData_tbunpacker_present;   //!
   TBranch        *b_HcalTBRunData_tbunpacker_obj_runType_;   //!
   TBranch        *b_HcalTBRunData_tbunpacker_obj_beamMode_;   //!
   TBranch        *b_HcalTBRunData_tbunpacker_obj_beamEnergyGeV_;   //!
   TBranch        *b_HcalTBTiming_tbunpacker_present;   //!
   TBranch        *b_HcalTBTiming_tbunpacker_obj_triggerTime_;   //!
   TBranch        *b_HcalTBTiming_tbunpacker_obj_ttcL1Atime_;   //!
   TBranch        *b_HcalTBTiming_tbunpacker_obj_beamCoincidence_;   //!
   TBranch        *b_HcalTBTiming_tbunpacker_obj_laserFlash_;   //!
   TBranch        *b_HcalTBTiming_tbunpacker_obj_qiePhase_;   //!
   TBranch        *b_HcalTBTiming_tbunpacker_obj_m1hits_;   //!
   TBranch        *b_HcalTBTiming_tbunpacker_obj_m2hits_;   //!
   TBranch        *b_HcalTBTiming_tbunpacker_obj_m3hits_;   //!
   TBranch        *b_HcalTBTiming_tbunpacker_obj_s1hits_;   //!
   TBranch        *b_HcalTBTiming_tbunpacker_obj_s2hits_;   //!
   TBranch        *b_HcalTBTiming_tbunpacker_obj_s3hits_;   //!
   TBranch        *b_HcalTBTiming_tbunpacker_obj_s4hits_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_present;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_runNumberSequenceId_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_runNumber_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_triggerWord_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_triggerTimeUsec_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_triggerTimeBase_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_spillNumber_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_orbitNumber_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_bunchNumber_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_eventNumber_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_flagsDaqTtype_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_algoBits3_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_algoBits2_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_algoBits1_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_algoBits0_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_techBits_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_gps1234_;   //!
   TBranch        *b_HcalTBTriggerData_tbunpacker_obj_gps5678_;   //!
   TBranch        *b_HcalTriggerPrimitiveDigi_unpacker_present;   //!
   TBranch        *b_HcalTriggerPrimitiveDigi_unpacker_obj_obj_;   //!
   TBranch        *b_HcalTriggerPrimitiveDigi_unpacker_obj_obj_id__id_;   //!
   TBranch        *b_HcalTriggerPrimitiveDigi_unpacker_obj_obj_size_;   //!
   TBranch        *b_HcalTriggerPrimitiveDigi_unpacker_obj_obj_hcalPresamples_;   //!
   TBranch        *b_HcalTriggerPrimitiveDigi_unpacker_obj_obj_data_;   //!
   TBranch        *b_Provenance_data__;   //!
   TBranch        *b_data__productID__id_;   //!
   TBranch        *b_data__parents;   //!
   TBranch        *b_data__cid;   //!
   TBranch        *b_data__status;   //!

   NewSelector(TTree *tree=0) { }
   virtual ~NewSelector() { }
   virtual Int_t   Version() const {return 1;}
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) {fInput = input;}
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(NewSelector,0);
};

#endif

#ifdef NewSelector_cxx
void NewSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses of the tree
   // will be set. It is normaly not necessary to make changes to the
   // generated code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running with PROOF.

   // Set branch addresses
   if (tree == 0) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("process_history_",&process_history_);
   fChain->SetBranchAddress("id_.run_",&id__run_);
   fChain->SetBranchAddress("id_.event_",&id__event_);
   fChain->SetBranchAddress("time_.timeLow_",&time__timeLow_);
   fChain->SetBranchAddress("time_.timeHigh_",&time__timeHigh_);
   fChain->SetBranchAddress("CaloJet_mcone5.present",&CaloJet_mcone5_present);
   fChain->SetBranchAddress("CaloJet_mcone5.obj",&CaloJet_mcone5_obj_);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.data.px",CaloJet_mcone5_obj_data_px);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.data.py",CaloJet_mcone5_obj_data_py);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.data.pz",CaloJet_mcone5_obj_data_pz);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.data.e",CaloJet_mcone5_obj_data_e);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.data.p",CaloJet_mcone5_obj_data_p);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.data.pt",CaloJet_mcone5_obj_data_pt);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.data.et",CaloJet_mcone5_obj_data_et);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.data.m",CaloJet_mcone5_obj_data_m);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.data.phi",CaloJet_mcone5_obj_data_phi);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.data.eta",CaloJet_mcone5_obj_data_eta);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.data.y",CaloJet_mcone5_obj_data_y);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.data.numberOfConstituents",CaloJet_mcone5_obj_data_numberOfConstituents);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.m_towerIdxs",CaloJet_mcone5_obj_m_towerIdxs);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.m_maxEInEmTowers",CaloJet_mcone5_obj_m_maxEInEmTowers);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.m_maxEInHadTowers",CaloJet_mcone5_obj_m_maxEInHadTowers);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.m_energyFractionInHCAL",CaloJet_mcone5_obj_m_energyFractionInHCAL);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.m_energyFractionInECAL",CaloJet_mcone5_obj_m_energyFractionInECAL);
   fChain->SetBranchAddress("CaloJet_mcone5.obj.m_n90",CaloJet_mcone5_obj_m_n90);
   fChain->SetBranchAddress("CaloJet_mcone7.present",&CaloJet_mcone7_present);
   fChain->SetBranchAddress("CaloJet_mcone7.obj",&CaloJet_mcone7_obj_);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.data.px",CaloJet_mcone7_obj_data_px);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.data.py",CaloJet_mcone7_obj_data_py);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.data.pz",CaloJet_mcone7_obj_data_pz);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.data.e",CaloJet_mcone7_obj_data_e);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.data.p",CaloJet_mcone7_obj_data_p);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.data.pt",CaloJet_mcone7_obj_data_pt);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.data.et",CaloJet_mcone7_obj_data_et);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.data.m",CaloJet_mcone7_obj_data_m);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.data.phi",CaloJet_mcone7_obj_data_phi);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.data.eta",CaloJet_mcone7_obj_data_eta);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.data.y",CaloJet_mcone7_obj_data_y);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.data.numberOfConstituents",CaloJet_mcone7_obj_data_numberOfConstituents);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.m_towerIdxs",CaloJet_mcone7_obj_m_towerIdxs);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.m_maxEInEmTowers",CaloJet_mcone7_obj_m_maxEInEmTowers);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.m_maxEInHadTowers",CaloJet_mcone7_obj_m_maxEInHadTowers);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.m_energyFractionInHCAL",CaloJet_mcone7_obj_m_energyFractionInHCAL);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.m_energyFractionInECAL",CaloJet_mcone7_obj_m_energyFractionInECAL);
   fChain->SetBranchAddress("CaloJet_mcone7.obj.m_n90",CaloJet_mcone7_obj_m_n90);
   fChain->SetBranchAddress("CaloTower_towermaker.present",&CaloTower_towermaker_present);
   fChain->SetBranchAddress("CaloTower_towermaker.obj.obj",&CaloTower_towermaker_obj_obj_);
   fChain->SetBranchAddress("CaloTower_towermaker.obj.obj.id_.id_",CaloTower_towermaker_obj_obj_id__id_);
   fChain->SetBranchAddress("CaloTower_towermaker.obj.obj.eT",CaloTower_towermaker_obj_obj_eT);
   fChain->SetBranchAddress("CaloTower_towermaker.obj.obj.eT_em",CaloTower_towermaker_obj_obj_eT_em);
   fChain->SetBranchAddress("CaloTower_towermaker.obj.obj.eT_had",CaloTower_towermaker_obj_obj_eT_had);
   fChain->SetBranchAddress("CaloTower_towermaker.obj.obj.eT_outer",CaloTower_towermaker_obj_obj_eT_outer);
   fChain->SetBranchAddress("CaloTower_towermaker.obj.obj.eta",CaloTower_towermaker_obj_obj_eta);
   fChain->SetBranchAddress("CaloTower_towermaker.obj.obj.phi",CaloTower_towermaker_obj_obj_phi);
   fChain->SetBranchAddress("CaloTower_towermaker.obj.obj.constituents",CaloTower_towermaker_obj_obj_constituents);
   fChain->SetBranchAddress("FEDRawDataCollection_HcalTBSource.present",&FEDRawDataCollection_HcalTBSource_present);
   fChain->SetBranchAddress("FEDRawDataCollection_HcalTBSource.obj.data_",&FEDRawDataCollection_HcalTBSource_obj_data__);
   fChain->SetBranchAddress("FEDRawDataCollection_HcalTBSource.obj.data_.data_",FEDRawDataCollection_HcalTBSource_obj_data__data_);
   fChain->SetBranchAddress("HBHEDataFrame_unpacker.present",&HBHEDataFrame_unpacker_present);
   fChain->SetBranchAddress("HBHEDataFrame_unpacker.obj.obj",&HBHEDataFrame_unpacker_obj_obj_);
   fChain->SetBranchAddress("HBHEDataFrame_unpacker.obj.obj.id_.id_",HBHEDataFrame_unpacker_obj_obj_id__id_);
   fChain->SetBranchAddress("HBHEDataFrame_unpacker.obj.obj.electronicsId_.hcalElectronicsId_",HBHEDataFrame_unpacker_obj_obj_electronicsId__hcalElectronicsId_);
   fChain->SetBranchAddress("HBHEDataFrame_unpacker.obj.obj.size_",HBHEDataFrame_unpacker_obj_obj_size_);
   fChain->SetBranchAddress("HBHEDataFrame_unpacker.obj.obj.hcalPresamples_",HBHEDataFrame_unpacker_obj_obj_hcalPresamples_);
   fChain->SetBranchAddress("HBHEDataFrame_unpacker.obj.obj.data_",HBHEDataFrame_unpacker_obj_obj_data_);
   fChain->SetBranchAddress("HBHERecHit_reco_hbhe.present",&HBHERecHit_reco_hbhe_present);
   fChain->SetBranchAddress("HBHERecHit_reco_hbhe.obj.obj",&HBHERecHit_reco_hbhe_obj_obj_);
   fChain->SetBranchAddress("HBHERecHit_reco_hbhe.obj.obj.id_.id_",HBHERecHit_reco_hbhe_obj_obj_id__id_);
   fChain->SetBranchAddress("HBHERecHit_reco_hbhe.obj.obj.energy_",HBHERecHit_reco_hbhe_obj_obj_energy_);
   fChain->SetBranchAddress("HBHERecHit_reco_hbhe.obj.obj.time_",HBHERecHit_reco_hbhe_obj_obj_time_);
   fChain->SetBranchAddress("HFDataFrame_unpacker.present",&HFDataFrame_unpacker_present);
   fChain->SetBranchAddress("HFDataFrame_unpacker.obj.obj",&HFDataFrame_unpacker_obj_obj_);
   fChain->SetBranchAddress("HFDataFrame_unpacker.obj.obj.id_.id_",&HFDataFrame_unpacker_obj_obj_id__id_);
   fChain->SetBranchAddress("HFDataFrame_unpacker.obj.obj.electronicsId_.hcalElectronicsId_",&HFDataFrame_unpacker_obj_obj_electronicsId__hcalElectronicsId_);
   fChain->SetBranchAddress("HFDataFrame_unpacker.obj.obj.size_",&HFDataFrame_unpacker_obj_obj_size_);
   fChain->SetBranchAddress("HFDataFrame_unpacker.obj.obj.hcalPresamples_",&HFDataFrame_unpacker_obj_obj_hcalPresamples_);
   fChain->SetBranchAddress("HFDataFrame_unpacker.obj.obj.data_",&HFDataFrame_unpacker_obj_obj_data_);
   fChain->SetBranchAddress("HFRecHit_reco_hf.present",&HFRecHit_reco_hf_present);
   fChain->SetBranchAddress("HFRecHit_reco_hf.obj.obj",&HFRecHit_reco_hf_obj_obj_);
   fChain->SetBranchAddress("HFRecHit_reco_hf.obj.obj.id_.id_",&HFRecHit_reco_hf_obj_obj_id__id_);
   fChain->SetBranchAddress("HFRecHit_reco_hf.obj.obj.energy_",&HFRecHit_reco_hf_obj_obj_energy_);
   fChain->SetBranchAddress("HFRecHit_reco_hf.obj.obj.time_",&HFRecHit_reco_hf_obj_obj_time_);
   fChain->SetBranchAddress("HODataFrame_unpacker.present",&HODataFrame_unpacker_present);
   fChain->SetBranchAddress("HODataFrame_unpacker.obj.obj",&HODataFrame_unpacker_obj_obj_);
   fChain->SetBranchAddress("HODataFrame_unpacker.obj.obj.id_.id_",HODataFrame_unpacker_obj_obj_id__id_);
   fChain->SetBranchAddress("HODataFrame_unpacker.obj.obj.electronicsId_.hcalElectronicsId_",HODataFrame_unpacker_obj_obj_electronicsId__hcalElectronicsId_);
   fChain->SetBranchAddress("HODataFrame_unpacker.obj.obj.size_",HODataFrame_unpacker_obj_obj_size_);
   fChain->SetBranchAddress("HODataFrame_unpacker.obj.obj.hcalPresamples_",HODataFrame_unpacker_obj_obj_hcalPresamples_);
   fChain->SetBranchAddress("HODataFrame_unpacker.obj.obj.data_",HODataFrame_unpacker_obj_obj_data_);
   fChain->SetBranchAddress("HORecHit_reco_ho.present",&HORecHit_reco_ho_present);
   fChain->SetBranchAddress("HORecHit_reco_ho.obj.obj",&HORecHit_reco_ho_obj_obj_);
   fChain->SetBranchAddress("HORecHit_reco_ho.obj.obj.id_.id_",HORecHit_reco_ho_obj_obj_id__id_);
   fChain->SetBranchAddress("HORecHit_reco_ho.obj.obj.energy_",HORecHit_reco_ho_obj_obj_energy_);
   fChain->SetBranchAddress("HORecHit_reco_ho.obj.obj.time_",HORecHit_reco_ho_obj_obj_time_);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.present",&HcalTBEventPosition_tbunpacker_present);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.obj.hfTableX_",&HcalTBEventPosition_tbunpacker_obj_hfTableX_);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.obj.hfTableY_",&HcalTBEventPosition_tbunpacker_obj_hfTableY_);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.obj.hfTableV_",&HcalTBEventPosition_tbunpacker_obj_hfTableV_);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.obj.hbheTableEta_",&HcalTBEventPosition_tbunpacker_obj_hbheTableEta_);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.obj.hbheTablePhi_",&HcalTBEventPosition_tbunpacker_obj_hbheTablePhi_);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.obj.ax_",&HcalTBEventPosition_tbunpacker_obj_ax_);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.obj.ay_",&HcalTBEventPosition_tbunpacker_obj_ay_);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.obj.bx_",&HcalTBEventPosition_tbunpacker_obj_bx_);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.obj.by_",&HcalTBEventPosition_tbunpacker_obj_by_);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.obj.cx_",&HcalTBEventPosition_tbunpacker_obj_cx_);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.obj.cy_",&HcalTBEventPosition_tbunpacker_obj_cy_);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.obj.dx_",&HcalTBEventPosition_tbunpacker_obj_dx_);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.obj.dy_",&HcalTBEventPosition_tbunpacker_obj_dy_);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.obj.ex_",&HcalTBEventPosition_tbunpacker_obj_ex_);
   fChain->SetBranchAddress("HcalTBEventPosition_tbunpacker.obj.ey_",&HcalTBEventPosition_tbunpacker_obj_ey_);
   fChain->SetBranchAddress("HcalTBRunData_tbunpacker.present",&HcalTBRunData_tbunpacker_present);
   fChain->SetBranchAddress("HcalTBRunData_tbunpacker.obj.runType_",&HcalTBRunData_tbunpacker_obj_runType_);
   fChain->SetBranchAddress("HcalTBRunData_tbunpacker.obj.beamMode_",&HcalTBRunData_tbunpacker_obj_beamMode_);
   fChain->SetBranchAddress("HcalTBRunData_tbunpacker.obj.beamEnergyGeV_",&HcalTBRunData_tbunpacker_obj_beamEnergyGeV_);
   fChain->SetBranchAddress("HcalTBTiming_tbunpacker.present",&HcalTBTiming_tbunpacker_present);
   fChain->SetBranchAddress("HcalTBTiming_tbunpacker.obj.triggerTime_",&HcalTBTiming_tbunpacker_obj_triggerTime_);
   fChain->SetBranchAddress("HcalTBTiming_tbunpacker.obj.ttcL1Atime_",&HcalTBTiming_tbunpacker_obj_ttcL1Atime_);
   fChain->SetBranchAddress("HcalTBTiming_tbunpacker.obj.beamCoincidence_",&HcalTBTiming_tbunpacker_obj_beamCoincidence_);
   fChain->SetBranchAddress("HcalTBTiming_tbunpacker.obj.laserFlash_",&HcalTBTiming_tbunpacker_obj_laserFlash_);
   fChain->SetBranchAddress("HcalTBTiming_tbunpacker.obj.qiePhase_",&HcalTBTiming_tbunpacker_obj_qiePhase_);
   fChain->SetBranchAddress("HcalTBTiming_tbunpacker.obj.m1hits_",&HcalTBTiming_tbunpacker_obj_m1hits_);
   fChain->SetBranchAddress("HcalTBTiming_tbunpacker.obj.m2hits_",&HcalTBTiming_tbunpacker_obj_m2hits_);
   fChain->SetBranchAddress("HcalTBTiming_tbunpacker.obj.m3hits_",&HcalTBTiming_tbunpacker_obj_m3hits_);
   fChain->SetBranchAddress("HcalTBTiming_tbunpacker.obj.s1hits_",&HcalTBTiming_tbunpacker_obj_s1hits_);
   fChain->SetBranchAddress("HcalTBTiming_tbunpacker.obj.s2hits_",&HcalTBTiming_tbunpacker_obj_s2hits_);
   fChain->SetBranchAddress("HcalTBTiming_tbunpacker.obj.s3hits_",&HcalTBTiming_tbunpacker_obj_s3hits_);
   fChain->SetBranchAddress("HcalTBTiming_tbunpacker.obj.s4hits_",&HcalTBTiming_tbunpacker_obj_s4hits_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.present",&HcalTBTriggerData_tbunpacker_present);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.runNumberSequenceId_",&HcalTBTriggerData_tbunpacker_obj_runNumberSequenceId_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.runNumber_",&HcalTBTriggerData_tbunpacker_obj_runNumber_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.triggerWord_",&HcalTBTriggerData_tbunpacker_obj_triggerWord_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.triggerTimeUsec_",&HcalTBTriggerData_tbunpacker_obj_triggerTimeUsec_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.triggerTimeBase_",&HcalTBTriggerData_tbunpacker_obj_triggerTimeBase_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.spillNumber_",&HcalTBTriggerData_tbunpacker_obj_spillNumber_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.orbitNumber_",&HcalTBTriggerData_tbunpacker_obj_orbitNumber_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.bunchNumber_",&HcalTBTriggerData_tbunpacker_obj_bunchNumber_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.eventNumber_",&HcalTBTriggerData_tbunpacker_obj_eventNumber_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.flagsDaqTtype_",&HcalTBTriggerData_tbunpacker_obj_flagsDaqTtype_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.algoBits3_",&HcalTBTriggerData_tbunpacker_obj_algoBits3_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.algoBits2_",&HcalTBTriggerData_tbunpacker_obj_algoBits2_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.algoBits1_",&HcalTBTriggerData_tbunpacker_obj_algoBits1_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.algoBits0_",&HcalTBTriggerData_tbunpacker_obj_algoBits0_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.techBits_",&HcalTBTriggerData_tbunpacker_obj_techBits_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.gps1234_",&HcalTBTriggerData_tbunpacker_obj_gps1234_);
   fChain->SetBranchAddress("HcalTBTriggerData_tbunpacker.obj.gps5678_",&HcalTBTriggerData_tbunpacker_obj_gps5678_);
   fChain->SetBranchAddress("HcalTriggerPrimitiveDigi_unpacker.present",&HcalTriggerPrimitiveDigi_unpacker_present);
   fChain->SetBranchAddress("HcalTriggerPrimitiveDigi_unpacker.obj.obj",&HcalTriggerPrimitiveDigi_unpacker_obj_obj_);
   fChain->SetBranchAddress("HcalTriggerPrimitiveDigi_unpacker.obj.obj.id_.id_",&HcalTriggerPrimitiveDigi_unpacker_obj_obj_id__id_);
   fChain->SetBranchAddress("HcalTriggerPrimitiveDigi_unpacker.obj.obj.size_",&HcalTriggerPrimitiveDigi_unpacker_obj_obj_size_);
   fChain->SetBranchAddress("HcalTriggerPrimitiveDigi_unpacker.obj.obj.hcalPresamples_",&HcalTriggerPrimitiveDigi_unpacker_obj_obj_hcalPresamples_);
   fChain->SetBranchAddress("HcalTriggerPrimitiveDigi_unpacker.obj.obj.data_",&HcalTriggerPrimitiveDigi_unpacker_obj_obj_data_);
   fChain->SetBranchAddress("data_",&data__);
   fChain->SetBranchAddress("data_.productID_.id_",data__productID__id_);
   fChain->SetBranchAddress("data_.parents",data__parents);
   fChain->SetBranchAddress("data_.cid",data__cid);
   fChain->SetBranchAddress("data_.status",data__status);
}

Bool_t NewSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. Typically here the branch pointers
   // will be retrieved. It is normaly not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed.

   // Get branch pointers
   printf("Processing file: %s\n",fChain->GetCurrentFile()->GetName());

   b_EventAux_process_history_ = fChain->GetBranch("process_history_");
   b_EventAux_id__run_ = fChain->GetBranch("id_.run_");
   b_EventAux_id__event_ = fChain->GetBranch("id_.event_");
   b_EventAux_time__timeLow_ = fChain->GetBranch("time_.timeLow_");
   b_EventAux_time__timeHigh_ = fChain->GetBranch("time_.timeHigh_");
   b_CaloJet_mcone5_present = fChain->GetBranch("CaloJet_mcone5.present");
   b_CaloJet_mcone5_obj_ = fChain->GetBranch("CaloJet_mcone5.obj");
   b_CaloJet_mcone5_obj_data_px = fChain->GetBranch("CaloJet_mcone5.obj.data.px");
   b_CaloJet_mcone5_obj_data_py = fChain->GetBranch("CaloJet_mcone5.obj.data.py");
   b_CaloJet_mcone5_obj_data_pz = fChain->GetBranch("CaloJet_mcone5.obj.data.pz");
   b_CaloJet_mcone5_obj_data_e = fChain->GetBranch("CaloJet_mcone5.obj.data.e");
   b_CaloJet_mcone5_obj_data_p = fChain->GetBranch("CaloJet_mcone5.obj.data.p");
   b_CaloJet_mcone5_obj_data_pt = fChain->GetBranch("CaloJet_mcone5.obj.data.pt");
   b_CaloJet_mcone5_obj_data_et = fChain->GetBranch("CaloJet_mcone5.obj.data.et");
   b_CaloJet_mcone5_obj_data_m = fChain->GetBranch("CaloJet_mcone5.obj.data.m");
   b_CaloJet_mcone5_obj_data_phi = fChain->GetBranch("CaloJet_mcone5.obj.data.phi");
   b_CaloJet_mcone5_obj_data_eta = fChain->GetBranch("CaloJet_mcone5.obj.data.eta");
   b_CaloJet_mcone5_obj_data_y = fChain->GetBranch("CaloJet_mcone5.obj.data.y");
   b_CaloJet_mcone5_obj_data_numberOfConstituents = fChain->GetBranch("CaloJet_mcone5.obj.data.numberOfConstituents");
   b_CaloJet_mcone5_obj_m_towerIdxs = fChain->GetBranch("CaloJet_mcone5.obj.m_towerIdxs");
   b_CaloJet_mcone5_obj_m_maxEInEmTowers = fChain->GetBranch("CaloJet_mcone5.obj.m_maxEInEmTowers");
   b_CaloJet_mcone5_obj_m_maxEInHadTowers = fChain->GetBranch("CaloJet_mcone5.obj.m_maxEInHadTowers");
   b_CaloJet_mcone5_obj_m_energyFractionInHCAL = fChain->GetBranch("CaloJet_mcone5.obj.m_energyFractionInHCAL");
   b_CaloJet_mcone5_obj_m_energyFractionInECAL = fChain->GetBranch("CaloJet_mcone5.obj.m_energyFractionInECAL");
   b_CaloJet_mcone5_obj_m_n90 = fChain->GetBranch("CaloJet_mcone5.obj.m_n90");
   b_CaloJet_mcone7_present = fChain->GetBranch("CaloJet_mcone7.present");
   b_CaloJet_mcone7_obj_ = fChain->GetBranch("CaloJet_mcone7.obj");
   b_CaloJet_mcone7_obj_data_px = fChain->GetBranch("CaloJet_mcone7.obj.data.px");
   b_CaloJet_mcone7_obj_data_py = fChain->GetBranch("CaloJet_mcone7.obj.data.py");
   b_CaloJet_mcone7_obj_data_pz = fChain->GetBranch("CaloJet_mcone7.obj.data.pz");
   b_CaloJet_mcone7_obj_data_e = fChain->GetBranch("CaloJet_mcone7.obj.data.e");
   b_CaloJet_mcone7_obj_data_p = fChain->GetBranch("CaloJet_mcone7.obj.data.p");
   b_CaloJet_mcone7_obj_data_pt = fChain->GetBranch("CaloJet_mcone7.obj.data.pt");
   b_CaloJet_mcone7_obj_data_et = fChain->GetBranch("CaloJet_mcone7.obj.data.et");
   b_CaloJet_mcone7_obj_data_m = fChain->GetBranch("CaloJet_mcone7.obj.data.m");
   b_CaloJet_mcone7_obj_data_phi = fChain->GetBranch("CaloJet_mcone7.obj.data.phi");
   b_CaloJet_mcone7_obj_data_eta = fChain->GetBranch("CaloJet_mcone7.obj.data.eta");
   b_CaloJet_mcone7_obj_data_y = fChain->GetBranch("CaloJet_mcone7.obj.data.y");
   b_CaloJet_mcone7_obj_data_numberOfConstituents = fChain->GetBranch("CaloJet_mcone7.obj.data.numberOfConstituents");
   b_CaloJet_mcone7_obj_m_towerIdxs = fChain->GetBranch("CaloJet_mcone7.obj.m_towerIdxs");
   b_CaloJet_mcone7_obj_m_maxEInEmTowers = fChain->GetBranch("CaloJet_mcone7.obj.m_maxEInEmTowers");
   b_CaloJet_mcone7_obj_m_maxEInHadTowers = fChain->GetBranch("CaloJet_mcone7.obj.m_maxEInHadTowers");
   b_CaloJet_mcone7_obj_m_energyFractionInHCAL = fChain->GetBranch("CaloJet_mcone7.obj.m_energyFractionInHCAL");
   b_CaloJet_mcone7_obj_m_energyFractionInECAL = fChain->GetBranch("CaloJet_mcone7.obj.m_energyFractionInECAL");
   b_CaloJet_mcone7_obj_m_n90 = fChain->GetBranch("CaloJet_mcone7.obj.m_n90");
   b_CaloTower_towermaker_present = fChain->GetBranch("CaloTower_towermaker.present");
   b_CaloTower_towermaker_obj_obj_ = fChain->GetBranch("CaloTower_towermaker.obj.obj");
   b_CaloTower_towermaker_obj_obj_id__id_ = fChain->GetBranch("CaloTower_towermaker.obj.obj.id_.id_");
   b_CaloTower_towermaker_obj_obj_eT = fChain->GetBranch("CaloTower_towermaker.obj.obj.eT");
   b_CaloTower_towermaker_obj_obj_eT_em = fChain->GetBranch("CaloTower_towermaker.obj.obj.eT_em");
   b_CaloTower_towermaker_obj_obj_eT_had = fChain->GetBranch("CaloTower_towermaker.obj.obj.eT_had");
   b_CaloTower_towermaker_obj_obj_eT_outer = fChain->GetBranch("CaloTower_towermaker.obj.obj.eT_outer");
   b_CaloTower_towermaker_obj_obj_eta = fChain->GetBranch("CaloTower_towermaker.obj.obj.eta");
   b_CaloTower_towermaker_obj_obj_phi = fChain->GetBranch("CaloTower_towermaker.obj.obj.phi");
   b_CaloTower_towermaker_obj_obj_constituents = fChain->GetBranch("CaloTower_towermaker.obj.obj.constituents");
   b_FEDRawDataCollection_HcalTBSource_present = fChain->GetBranch("FEDRawDataCollection_HcalTBSource.present");
   b_FEDRawDataCollection_HcalTBSource_obj_data__ = fChain->GetBranch("FEDRawDataCollection_HcalTBSource.obj.data_");
   b_FEDRawDataCollection_HcalTBSource_obj_data__data_ = fChain->GetBranch("FEDRawDataCollection_HcalTBSource.obj.data_.data_");
   b_HBHEDataFrame_unpacker_present = fChain->GetBranch("HBHEDataFrame_unpacker.present");
   b_HBHEDataFrame_unpacker_obj_obj_ = fChain->GetBranch("HBHEDataFrame_unpacker.obj.obj");
   b_HBHEDataFrame_unpacker_obj_obj_id__id_ = fChain->GetBranch("HBHEDataFrame_unpacker.obj.obj.id_.id_");
   b_HBHEDataFrame_unpacker_obj_obj_electronicsId__hcalElectronicsId_ = fChain->GetBranch("HBHEDataFrame_unpacker.obj.obj.electronicsId_.hcalElectronicsId_");
   b_HBHEDataFrame_unpacker_obj_obj_size_ = fChain->GetBranch("HBHEDataFrame_unpacker.obj.obj.size_");
   b_HBHEDataFrame_unpacker_obj_obj_hcalPresamples_ = fChain->GetBranch("HBHEDataFrame_unpacker.obj.obj.hcalPresamples_");
   b_HBHEDataFrame_unpacker_obj_obj_data_ = fChain->GetBranch("HBHEDataFrame_unpacker.obj.obj.data_");
   b_HBHERecHit_reco_hbhe_present = fChain->GetBranch("HBHERecHit_reco_hbhe.present");
   b_HBHERecHit_reco_hbhe_obj_obj_ = fChain->GetBranch("HBHERecHit_reco_hbhe.obj.obj");
   b_HBHERecHit_reco_hbhe_obj_obj_id__id_ = fChain->GetBranch("HBHERecHit_reco_hbhe.obj.obj.id_.id_");
   b_HBHERecHit_reco_hbhe_obj_obj_energy_ = fChain->GetBranch("HBHERecHit_reco_hbhe.obj.obj.energy_");
   b_HBHERecHit_reco_hbhe_obj_obj_time_ = fChain->GetBranch("HBHERecHit_reco_hbhe.obj.obj.time_");
   b_HFDataFrame_unpacker_present = fChain->GetBranch("HFDataFrame_unpacker.present");
   b_HFDataFrame_unpacker_obj_obj_ = fChain->GetBranch("HFDataFrame_unpacker.obj.obj");
   b_HFDataFrame_unpacker_obj_obj_id__id_ = fChain->GetBranch("HFDataFrame_unpacker.obj.obj.id_.id_");
   b_HFDataFrame_unpacker_obj_obj_electronicsId__hcalElectronicsId_ = fChain->GetBranch("HFDataFrame_unpacker.obj.obj.electronicsId_.hcalElectronicsId_");
   b_HFDataFrame_unpacker_obj_obj_size_ = fChain->GetBranch("HFDataFrame_unpacker.obj.obj.size_");
   b_HFDataFrame_unpacker_obj_obj_hcalPresamples_ = fChain->GetBranch("HFDataFrame_unpacker.obj.obj.hcalPresamples_");
   b_HFDataFrame_unpacker_obj_obj_data_ = fChain->GetBranch("HFDataFrame_unpacker.obj.obj.data_");
   b_HFRecHit_reco_hf_present = fChain->GetBranch("HFRecHit_reco_hf.present");
   b_HFRecHit_reco_hf_obj_obj_ = fChain->GetBranch("HFRecHit_reco_hf.obj.obj");
   b_HFRecHit_reco_hf_obj_obj_id__id_ = fChain->GetBranch("HFRecHit_reco_hf.obj.obj.id_.id_");
   b_HFRecHit_reco_hf_obj_obj_energy_ = fChain->GetBranch("HFRecHit_reco_hf.obj.obj.energy_");
   b_HFRecHit_reco_hf_obj_obj_time_ = fChain->GetBranch("HFRecHit_reco_hf.obj.obj.time_");
   b_HODataFrame_unpacker_present = fChain->GetBranch("HODataFrame_unpacker.present");
   b_HODataFrame_unpacker_obj_obj_ = fChain->GetBranch("HODataFrame_unpacker.obj.obj");
   b_HODataFrame_unpacker_obj_obj_id__id_ = fChain->GetBranch("HODataFrame_unpacker.obj.obj.id_.id_");
   b_HODataFrame_unpacker_obj_obj_electronicsId__hcalElectronicsId_ = fChain->GetBranch("HODataFrame_unpacker.obj.obj.electronicsId_.hcalElectronicsId_");
   b_HODataFrame_unpacker_obj_obj_size_ = fChain->GetBranch("HODataFrame_unpacker.obj.obj.size_");
   b_HODataFrame_unpacker_obj_obj_hcalPresamples_ = fChain->GetBranch("HODataFrame_unpacker.obj.obj.hcalPresamples_");
   b_HODataFrame_unpacker_obj_obj_data_ = fChain->GetBranch("HODataFrame_unpacker.obj.obj.data_");
   b_HORecHit_reco_ho_present = fChain->GetBranch("HORecHit_reco_ho.present");
   b_HORecHit_reco_ho_obj_obj_ = fChain->GetBranch("HORecHit_reco_ho.obj.obj");
   b_HORecHit_reco_ho_obj_obj_id__id_ = fChain->GetBranch("HORecHit_reco_ho.obj.obj.id_.id_");
   b_HORecHit_reco_ho_obj_obj_energy_ = fChain->GetBranch("HORecHit_reco_ho.obj.obj.energy_");
   b_HORecHit_reco_ho_obj_obj_time_ = fChain->GetBranch("HORecHit_reco_ho.obj.obj.time_");
   b_HcalTBEventPosition_tbunpacker_present = fChain->GetBranch("HcalTBEventPosition_tbunpacker.present");
   b_HcalTBEventPosition_tbunpacker_obj_hfTableX_ = fChain->GetBranch("HcalTBEventPosition_tbunpacker.obj.hfTableX_");
   b_HcalTBEventPosition_tbunpacker_obj_hfTableY_ = fChain->GetBranch("HcalTBEventPosition_tbunpacker.obj.hfTableY_");
   b_HcalTBEventPosition_tbunpacker_obj_hfTableV_ = fChain->GetBranch("HcalTBEventPosition_tbunpacker.obj.hfTableV_");
   b_HcalTBEventPosition_tbunpacker_obj_hbheTableEta_ = fChain->GetBranch("HcalTBEventPosition_tbunpacker.obj.hbheTableEta_");
   b_HcalTBEventPosition_tbunpacker_obj_hbheTablePhi_ = fChain->GetBranch("HcalTBEventPosition_tbunpacker.obj.hbheTablePhi_");
   b_HcalTBEventPosition_tbunpacker_obj_ax_ = fChain->GetBranch("HcalTBEventPosition_tbunpacker.obj.ax_");
   b_HcalTBEventPosition_tbunpacker_obj_ay_ = fChain->GetBranch("HcalTBEventPosition_tbunpacker.obj.ay_");
   b_HcalTBEventPosition_tbunpacker_obj_bx_ = fChain->GetBranch("HcalTBEventPosition_tbunpacker.obj.bx_");
   b_HcalTBEventPosition_tbunpacker_obj_by_ = fChain->GetBranch("HcalTBEventPosition_tbunpacker.obj.by_");
   b_HcalTBEventPosition_tbunpacker_obj_cx_ = fChain->GetBranch("HcalTBEventPosition_tbunpacker.obj.cx_");
   b_HcalTBEventPosition_tbunpacker_obj_cy_ = fChain->GetBranch("HcalTBEventPosition_tbunpacker.obj.cy_");
   b_HcalTBEventPosition_tbunpacker_obj_dx_ = fChain->GetBranch("HcalTBEventPosition_tbunpacker.obj.dx_");
   b_HcalTBEventPosition_tbunpacker_obj_dy_ = fChain->GetBranch("HcalTBEventPosition_tbunpacker.obj.dy_");
   b_HcalTBEventPosition_tbunpacker_obj_ex_ = fChain->GetBranch("HcalTBEventPosition_tbunpacker.obj.ex_");
   b_HcalTBEventPosition_tbunpacker_obj_ey_ = fChain->GetBranch("HcalTBEventPosition_tbunpacker.obj.ey_");
   b_HcalTBRunData_tbunpacker_present = fChain->GetBranch("HcalTBRunData_tbunpacker.present");
   b_HcalTBRunData_tbunpacker_obj_runType_ = fChain->GetBranch("HcalTBRunData_tbunpacker.obj.runType_");
   b_HcalTBRunData_tbunpacker_obj_beamMode_ = fChain->GetBranch("HcalTBRunData_tbunpacker.obj.beamMode_");
   b_HcalTBRunData_tbunpacker_obj_beamEnergyGeV_ = fChain->GetBranch("HcalTBRunData_tbunpacker.obj.beamEnergyGeV_");
   b_HcalTBTiming_tbunpacker_present = fChain->GetBranch("HcalTBTiming_tbunpacker.present");
   b_HcalTBTiming_tbunpacker_obj_triggerTime_ = fChain->GetBranch("HcalTBTiming_tbunpacker.obj.triggerTime_");
   b_HcalTBTiming_tbunpacker_obj_ttcL1Atime_ = fChain->GetBranch("HcalTBTiming_tbunpacker.obj.ttcL1Atime_");
   b_HcalTBTiming_tbunpacker_obj_beamCoincidence_ = fChain->GetBranch("HcalTBTiming_tbunpacker.obj.beamCoincidence_");
   b_HcalTBTiming_tbunpacker_obj_laserFlash_ = fChain->GetBranch("HcalTBTiming_tbunpacker.obj.laserFlash_");
   b_HcalTBTiming_tbunpacker_obj_qiePhase_ = fChain->GetBranch("HcalTBTiming_tbunpacker.obj.qiePhase_");
   b_HcalTBTiming_tbunpacker_obj_m1hits_ = fChain->GetBranch("HcalTBTiming_tbunpacker.obj.m1hits_");
   b_HcalTBTiming_tbunpacker_obj_m2hits_ = fChain->GetBranch("HcalTBTiming_tbunpacker.obj.m2hits_");
   b_HcalTBTiming_tbunpacker_obj_m3hits_ = fChain->GetBranch("HcalTBTiming_tbunpacker.obj.m3hits_");
   b_HcalTBTiming_tbunpacker_obj_s1hits_ = fChain->GetBranch("HcalTBTiming_tbunpacker.obj.s1hits_");
   b_HcalTBTiming_tbunpacker_obj_s2hits_ = fChain->GetBranch("HcalTBTiming_tbunpacker.obj.s2hits_");
   b_HcalTBTiming_tbunpacker_obj_s3hits_ = fChain->GetBranch("HcalTBTiming_tbunpacker.obj.s3hits_");
   b_HcalTBTiming_tbunpacker_obj_s4hits_ = fChain->GetBranch("HcalTBTiming_tbunpacker.obj.s4hits_");
   b_HcalTBTriggerData_tbunpacker_present = fChain->GetBranch("HcalTBTriggerData_tbunpacker.present");
   b_HcalTBTriggerData_tbunpacker_obj_runNumberSequenceId_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.runNumberSequenceId_");
   b_HcalTBTriggerData_tbunpacker_obj_runNumber_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.runNumber_");
   b_HcalTBTriggerData_tbunpacker_obj_triggerWord_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.triggerWord_");
   b_HcalTBTriggerData_tbunpacker_obj_triggerTimeUsec_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.triggerTimeUsec_");
   b_HcalTBTriggerData_tbunpacker_obj_triggerTimeBase_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.triggerTimeBase_");
   b_HcalTBTriggerData_tbunpacker_obj_spillNumber_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.spillNumber_");
   b_HcalTBTriggerData_tbunpacker_obj_orbitNumber_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.orbitNumber_");
   b_HcalTBTriggerData_tbunpacker_obj_bunchNumber_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.bunchNumber_");
   b_HcalTBTriggerData_tbunpacker_obj_eventNumber_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.eventNumber_");
   b_HcalTBTriggerData_tbunpacker_obj_flagsDaqTtype_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.flagsDaqTtype_");
   b_HcalTBTriggerData_tbunpacker_obj_algoBits3_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.algoBits3_");
   b_HcalTBTriggerData_tbunpacker_obj_algoBits2_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.algoBits2_");
   b_HcalTBTriggerData_tbunpacker_obj_algoBits1_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.algoBits1_");
   b_HcalTBTriggerData_tbunpacker_obj_algoBits0_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.algoBits0_");
   b_HcalTBTriggerData_tbunpacker_obj_techBits_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.techBits_");
   b_HcalTBTriggerData_tbunpacker_obj_gps1234_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.gps1234_");
   b_HcalTBTriggerData_tbunpacker_obj_gps5678_ = fChain->GetBranch("HcalTBTriggerData_tbunpacker.obj.gps5678_");
   b_HcalTriggerPrimitiveDigi_unpacker_present = fChain->GetBranch("HcalTriggerPrimitiveDigi_unpacker.present");
   b_HcalTriggerPrimitiveDigi_unpacker_obj_obj_ = fChain->GetBranch("HcalTriggerPrimitiveDigi_unpacker.obj.obj");
   b_HcalTriggerPrimitiveDigi_unpacker_obj_obj_id__id_ = fChain->GetBranch("HcalTriggerPrimitiveDigi_unpacker.obj.obj.id_.id_");
   b_HcalTriggerPrimitiveDigi_unpacker_obj_obj_size_ = fChain->GetBranch("HcalTriggerPrimitiveDigi_unpacker.obj.obj.size_");
   b_HcalTriggerPrimitiveDigi_unpacker_obj_obj_hcalPresamples_ = fChain->GetBranch("HcalTriggerPrimitiveDigi_unpacker.obj.obj.hcalPresamples_");
   b_HcalTriggerPrimitiveDigi_unpacker_obj_obj_data_ = fChain->GetBranch("HcalTriggerPrimitiveDigi_unpacker.obj.obj.data_");
   b_Provenance_data__ = fChain->GetBranch("data_");
   b_data__productID__id_ = fChain->GetBranch("data_.productID_.id_");
   b_data__parents = fChain->GetBranch("data_.parents");
   b_data__cid = fChain->GetBranch("data_.cid");
   b_data__status = fChain->GetBranch("data_.status");

   return kTRUE;
}

#endif // #ifdef NewSelector_cxx
