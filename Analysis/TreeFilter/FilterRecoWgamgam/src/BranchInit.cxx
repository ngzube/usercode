#include <algorithm>
#include <iostream>
#include "TTree.h"
#include "TChain.h"
#include "/afs/cern.ch/user/j/jkunkle/usercode/Analysis/TreeFilter/FilterRecoWgamgam/FilterRecoWgamgam/BranchInit.h"
#include "/afs/cern.ch/user/j/jkunkle/usercode/Analysis/TreeFilter/FilterRecoWgamgam/FilterRecoWgamgam/BranchDefs.h"

namespace IN {
 Int_t				nHLT;
 Int_t				nVtx;
 Int_t				nVtxBS;
 Int_t				nMC;
 Int_t				nPUInfo;
 Int_t				nEle;
 Int_t				nPho;
 Int_t				nMu;
 Int_t				nPFPho;
 Int_t				nJet;
 Int_t				nConv;
 Int_t				nLowPtJet;
 Int_t				run;
 Long64_t				event;
 Int_t				lumis;
 Bool_t				isData;
 Int_t				HLT[444];
 Int_t				HLTIndex[70];
 Float_t				bspotPos[3];
 Float_t				vtx[55][3];
 Int_t				IsVtxGood;
 Int_t				nGoodVtx;
 Float_t				vtxbs[55][3];
 Float_t				pdf[7];
 Float_t				pthat;
 Float_t				processID;
 Int_t				mcPID[52];
 Float_t				mcVtx[52][3];
 Float_t				mcPt[52];
 Float_t				mcEta[52];
 Float_t				mcPhi[52];
 Float_t				mcE[52];
 Int_t				mcGMomPID[52];
 Int_t				mcMomPID[52];
 Float_t				mcMomPt[52];
 Float_t				mcMomMass[52];
 Float_t				mcMomEta[52];
 Float_t				mcMomPhi[52];
 Int_t				mcIndex[52];
 Int_t				mcDecayType[52];
 Int_t				mcParentage[52];
 Int_t				mcStatus[52];
 Float_t				genMET;
 Float_t				genMETPhi;
 Int_t				nPU[4];
 Int_t				puBX[4];
 Float_t				puTrue[4];
 Float_t				pfMET;
 Float_t				pfMETPhi;
 Float_t				pfMETsumEt;
 Float_t				pfMETmEtSig;
 Float_t				pfMETSig;
 Float_t				recoPfMET;
 Float_t				recoPfMETPhi;
 Float_t				recoPfMETsumEt;
 Float_t				recoPfMETmEtSig;
 Float_t				recoPfMETSig;
 Float_t				trkMETxPV;
 Float_t				trkMETyPV;
 Float_t				trkMETPhiPV;
 Float_t				trkMETPV;
 Float_t				trkMETx[55];
 Float_t				trkMETy[55];
 Float_t				trkMETPhi[55];
 Float_t				trkMET[55];
 Int_t				metFilters[10];
 Int_t				eleTrg[7][16];
 Int_t				eleClass[7];
 Int_t				eleIsEcalDriven[7];
 Int_t				eleCharge[7];
 Float_t				eleEn[7];
 Float_t				eleEcalEn[7];
 Float_t				eleSCRawEn[7];
 Float_t				eleSCEn[7];
 Float_t				eleESEn[7];
 Float_t				elePt[7];
 Float_t				eleEta[7];
 Float_t				elePhi[7];
 Float_t				eleEtaVtx[7][100];
 Float_t				elePhiVtx[7][100];
 Float_t				eleEtVtx[7][100];
 Float_t				eleSCEta[7];
 Float_t				eleSCPhi[7];
 Float_t				eleSCEtaWidth[7];
 Float_t				eleSCPhiWidth[7];
 Float_t				eleVtx[7][3];
 Float_t				eleD0[7];
 Float_t				eleDz[7];
 Float_t				eleD0GV[7];
 Float_t				eleDzGV[7];
 Float_t				eleD0Vtx[7][100];
 Float_t				eleDzVtx[7][100];
 Float_t				eleHoverE[7];
 Float_t				eleHoverE12[7];
 Float_t				eleEoverP[7];
 Float_t				elePin[7];
 Float_t				elePout[7];
 Float_t				eleTrkMomErr[7];
 Float_t				eleBrem[7];
 Float_t				eledEtaAtVtx[7];
 Float_t				eledPhiAtVtx[7];
 Float_t				eleSigmaIEtaIEta[7];
 Float_t				eleSigmaIEtaIPhi[7];
 Float_t				eleSigmaIPhiIPhi[7];
 Float_t				eleEmax[7];
 Float_t				eleE1x5[7];
 Float_t				eleE3x3[7];
 Float_t				eleE5x5[7];
 Float_t				eleE2x5Max[7];
 Float_t				eleRegrE[7];
 Float_t				eleRegrEerr[7];
 Float_t				elePhoRegrE[7];
 Float_t				elePhoRegrEerr[7];
 Float_t				eleSeedTime[7];
 Int_t				eleRecoFlag[7];
 Int_t				elePos[7];
 Int_t				eleGenIndex[7];
 Int_t				eleGenGMomPID[7];
 Int_t				eleGenMomPID[7];
 Float_t				eleGenMomPt[7];
 Float_t				eleIsoTrkDR03[7];
 Float_t				eleIsoEcalDR03[7];
 Float_t				eleIsoHcalDR03[7];
 Float_t				eleIsoHcalDR0312[7];
 Float_t				eleIsoTrkDR04[7];
 Float_t				eleIsoEcalDR04[7];
 Float_t				eleIsoHcalDR04[7];
 Float_t				eleIsoHcalDR0412[7];
 Float_t				eleModIsoTrk[7];
 Float_t				eleModIsoEcal[7];
 Float_t				eleModIsoHcal[7];
 Int_t				eleMissHits[7];
 Float_t				eleConvDist[7];
 Float_t				eleConvDcot[7];
 Int_t				eleConvVtxFit[7];
 Float_t				eleIP3D[7];
 Float_t				eleIP3DErr[7];
 Float_t				eleIDMVANonTrig[7];
 Float_t				eleIDMVATrig[7];
 Float_t				eleIDMVATrigIDIso[7];
 Float_t				elePFChIso03[7];
 Float_t				elePFPhoIso03[7];
 Float_t				elePFNeuIso03[7];
 Float_t				elePFChIso04[7];
 Float_t				elePFPhoIso04[7];
 Float_t				elePFNeuIso04[7];
 Float_t				eleESEffSigmaRR[7][3];
 Int_t				phoTrg[9][8];
 Int_t				phoTrgFilter[9][50];
 Bool_t				phoIsPhoton[9];
 Float_t				phoSCPos[9][3];
 Float_t				phoCaloPos[9][3];
 Float_t				phoE[9];
 Float_t				phoEt[9];
 Float_t				phoEta[9];
 Float_t				phoVtx[9][3];
 Float_t				phoPhi[9];
 Float_t				phoR9[9];
 Float_t				phoTrkIsoHollowDR03[9];
 Float_t				phoEcalIsoDR03[9];
 Float_t				phoHcalIsoDR03[9];
 Float_t				phoHcalIsoDR0312[9];
 Float_t				phoTrkIsoHollowDR04[9];
 Float_t				phoCiCTrkIsoDR03[9][100];
 Float_t				phoCiCTrkIsoDR04[9][100];
 Float_t				phoCiCdRtoTrk[9];
 Float_t				phoEcalIsoDR04[9];
 Float_t				phoHcalIsoDR04[9];
 Float_t				phoHcalIsoDR0412[9];
 Float_t				phoHoverE[9];
 Float_t				phoHoverE12[9];
 Int_t				phoEleVeto[9];
 Float_t				phoSigmaIEtaIEta[9];
 Float_t				phoSigmaIEtaIPhi[9];
 Float_t				phoSigmaIPhiIPhi[9];
 Float_t				phoCiCPF4phopfIso03[9];
 Float_t				phoCiCPF4phopfIso04[9];
 Float_t				phoCiCPF4chgpfIso02[9][100];
 Float_t				phoCiCPF4chgpfIso03[9][100];
 Float_t				phoCiCPF4chgpfIso04[9][100];
 Float_t				phoEmax[9];
 Float_t				phoE3x3[9];
 Float_t				phoE3x1[9];
 Float_t				phoE1x3[9];
 Float_t				phoE5x5[9];
 Float_t				phoE1x5[9];
 Float_t				phoE2x2[9];
 Float_t				phoE2x5Max[9];
 Float_t				phoPFChIso[9];
 Float_t				phoPFPhoIso[9];
 Float_t				phoPFNeuIso[9];
 Float_t				phoSCRChIso[9];
 Float_t				phoSCRPhoIso[9];
 Float_t				phoSCRNeuIso[9];
 Float_t				phoRegrE[9];
 Float_t				phoRegrEerr[9];
 Float_t				phoSeedTime[9];
 Int_t				phoSeedDetId1[9];
 Int_t				phoSeedDetId2[9];
 Float_t				phoLICTD[9];
 Int_t				phoRecoFlag[9];
 Int_t				phoPos[9];
 Int_t				phoGenIndex[9];
 Int_t				phoGenGMomPID[9];
 Int_t				phoGenMomPID[9];
 Float_t				phoGenMomPt[9];
 Float_t				phoSCE[9];
 Float_t				phoSCRawE[9];
 Float_t				phoESEn[9];
 Float_t				phoSCEt[9];
 Float_t				phoSCEta[9];
 Float_t				phoSCPhi[9];
 Float_t				phoSCEtaWidth[9];
 Float_t				phoSCPhiWidth[9];
 Float_t				phoSCBrem[9];
 Int_t				phoOverlap[9];
 Int_t				phohasPixelSeed[9];
 Int_t				pho_hasConvPf[9];
 Int_t				pho_hasSLConvPf[9];
 Float_t				pho_pfconvVtxZ[9];
 Float_t				pho_pfconvVtxZErr[9];
 Int_t				pho_nSLConv[9];
 Float_t				pho_pfSLConvPos[9][20][3];
 Float_t				pho_pfSLConvVtxZ[9][20];
 Int_t				phoIsConv[9];
 Int_t				phoNConv[9];
 Float_t				phoConvInvMass[9];
 Float_t				phoConvCotTheta[9];
 Float_t				phoConvEoverP[9];
 Float_t				phoConvZofPVfromTrks[9];
 Float_t				phoConvMinDist[9];
 Float_t				phoConvdPhiAtVtx[9];
 Float_t				phoConvdPhiAtCalo[9];
 Float_t				phoConvdEtaAtCalo[9];
 Float_t				phoConvTrkd0[9][2];
 Float_t				phoConvTrkPin[9][2];
 Float_t				phoConvTrkPout[9][2];
 Float_t				phoConvTrkdz[9][2];
 Float_t				phoConvTrkdzErr[9][2];
 Float_t				phoConvChi2[9];
 Float_t				phoConvChi2Prob[9];
 Int_t				phoConvNTrks[9];
 Float_t				phoConvCharge[9][2];
 Float_t				phoConvValidVtx[9];
 Float_t				phoConvLikeLihood[9];
 Float_t				phoConvP4[9][4];
 Float_t				phoConvVtx[9][3];
 Float_t				phoConvVtxErr[9][3];
 Float_t				phoConvPairMomentum[9][3];
 Float_t				phoConvRefittedMomentum[9][3];
 Int_t				SingleLegConv[9];
 Float_t				phoPFConvVtx[9][3];
 Float_t				phoPFConvMom[9][3];
 Float_t				phoESEffSigmaRR[9][3];
 Int_t				muTrg[8][10];
 Float_t				muEta[8];
 Float_t				muPhi[8];
 Int_t				muCharge[8];
 Float_t				muPt[8];
 Float_t				muPz[8];
 Float_t				muVtx[8][3];
 Float_t				muVtxGlb[8][3];
 Int_t				muGenIndex[8];
 Float_t				mucktPt[8];
 Float_t				mucktPtErr[8];
 Float_t				mucktEta[8];
 Float_t				mucktPhi[8];
 Float_t				mucktdxy[8];
 Float_t				mucktdz[8];
 Float_t				muIsoTrk[8];
 Float_t				muIsoCalo[8];
 Float_t				muIsoEcal[8];
 Float_t				muIsoHcal[8];
 Float_t				muChi2NDF[8];
 Float_t				muInnerChi2NDF[8];
 Float_t				muPFIsoR04_CH[8];
 Float_t				muPFIsoR04_NH[8];
 Float_t				muPFIsoR04_Pho[8];
 Float_t				muPFIsoR04_PU[8];
 Float_t				muPFIsoR04_CPart[8];
 Float_t				muPFIsoR04_NHHT[8];
 Float_t				muPFIsoR04_PhoHT[8];
 Float_t				muPFIsoR03_CH[8];
 Float_t				muPFIsoR03_NH[8];
 Float_t				muPFIsoR03_Pho[8];
 Float_t				muPFIsoR03_PU[8];
 Float_t				muPFIsoR03_CPart[8];
 Float_t				muPFIsoR03_NHHT[8];
 Float_t				muPFIsoR03_PhoHT[8];
 Int_t				muType[8];
 Float_t				muD0[8];
 Float_t				muDz[8];
 Float_t				muD0GV[8];
 Float_t				muDzGV[8];
 Float_t				muD0Vtx[8][100];
 Float_t				muDzVtx[8][100];
 Float_t				muInnerD0[8];
 Float_t				muInnerDz[8];
 Float_t				muInnerD0GV[8];
 Float_t				muInnerDzGV[8];
 Float_t				muInnerPt[8];
 Float_t				muInnerPtErr[8];
 Int_t				muNumberOfValidTrkLayers[8];
 Int_t				muNumberOfValidTrkHits[8];
 Int_t				muNumberOfValidPixelLayers[8];
 Int_t				muNumberOfValidPixelHits[8];
 Int_t				muNumberOfValidMuonHits[8];
 Int_t				muStations[8];
 Int_t				muChambers[8];
 Float_t				muIP3D[8];
 Float_t				muIP3DErr[8];
 Float_t				PFPhoEt[42];
 Float_t				PFPhoEta[42];
 Float_t				PFPhoPhi[42];
 Int_t				PFPhoType[42];
 Float_t				PFPhoIso[42];
 Float_t				rho25;
 Float_t				rho25_neu;
 Float_t				rho25_muPFiso;
 Float_t				rho25_elePFiso;
 Float_t				rho2011;
 Float_t				rho2012;
 Int_t				jetTrg[16][14];
 Float_t				jetEn[16];
 Float_t				jetPt[16];
 Float_t				jetEta[16];
 Float_t				jetPhi[16];
 Float_t				jetCharge[16];
 Float_t				jetEt[16];
 Float_t				jetRawPt[16];
 Float_t				jetRawEn[16];
 Float_t				jetArea[16];
 Float_t				jetCHF[16];
 Float_t				jetNHF[16];
 Float_t				jetCEF[16];
 Float_t				jetNEF[16];
 Int_t				jetNCH[16];
 Float_t				jetHFHAE[16];
 Float_t				jetHFEME[16];
 Int_t				jetNConstituents[16];
 Float_t				jetCombinedSecondaryVtxBJetTags[16];
 Float_t				jetCombinedSecondaryVtxMVABJetTags[16];
 Float_t				jetJetProbabilityBJetTags[16];
 Float_t				jetJetBProbabilityBJetTags[16];
 Float_t				jetTrackCountingHighPurBJetTags[16];
 Float_t				jetBetaStar[16][100];
 Bool_t				jetPFLooseId[16];
 Float_t				jetDRMean[16];
 Float_t				jetDR2Mean[16];
 Float_t				jetDZ[16];
 Float_t				jetFrac01[16];
 Float_t				jetFrac02[16];
 Float_t				jetFrac03[16];
 Float_t				jetFrac04[16];
 Float_t				jetFrac05[16];
 Float_t				jetFrac06[16];
 Float_t				jetFrac07[16];
 Float_t				jetBeta[16];
 Float_t				jetBetaStarCMG[16];
 Float_t				jetBetaStarClassic[16];
 Float_t				jetBetaExt[16][100];
 Float_t				jetNNeutrals[16];
 Float_t				jetNCharged[16];
 Float_t				jetMVAs[16][4];
 Int_t				jetWPLevels[16][4];
 Float_t				jetMt[16];
 Float_t				jetJECUnc[16];
 Float_t				jetLeadTrackPt[16];
 Float_t				jetVtxPt[16];
 Float_t				jetVtxMass[16];
 Float_t				jetVtx3dL[16];
 Float_t				jetVtx3deL[16];
 Float_t				jetSoftLeptPt[16];
 Float_t				jetSoftLeptPtRel[16];
 Float_t				jetSoftLeptdR[16];
 Float_t				jetSoftLeptIdlooseMu[16];
 Float_t				jetSoftLeptIdEle95[16];
 Float_t				jetDPhiMETJet[16];
 Float_t				jetPuJetIdL[16];
 Float_t				jetPuJetIdM[16];
 Float_t				jetPuJetIdT[16];
 Int_t				jetPartonID[16];
 Int_t				jetGenJetIndex[16];
 Float_t				jetGenJetEn[16];
 Float_t				jetGenJetPt[16];
 Float_t				jetGenJetEta[16];
 Float_t				jetGenJetPhi[16];
 Int_t				jetGenPartonID[16];
 Float_t				jetGenEn[16];
 Float_t				jetGenPt[16];
 Float_t				jetGenEta[16];
 Float_t				jetGenPhi[16];
 Float_t				convVtx[67][3];
 Float_t				convVtxErr[67][3];
 Float_t				convPairMomentum[67][3];
 Float_t				convRefittedMomentum[67][3];
 Int_t				convNTracks[67];
 Float_t				convPairInvMass[67];
 Float_t				convPairCotThetaSep[67];
 Float_t				convEoverP[67];
 Float_t				convDistOfMinApproach[67];
 Float_t				convDPhiTrksAtVtx[67];
 Float_t				convDPhiTrksAtEcal[67];
 Float_t				convDEtaTrksAtEcal[67];
 Float_t				convDxy[67];
 Float_t				convDz[67];
 Float_t				convLxy[67];
 Float_t				convLz[67];
 Float_t				convZofPrimVtxFromTrks[67];
 Int_t				convNHitsBeforeVtx[67][2];
 Int_t				convNSharedHits[67];
 Int_t				convValidVtx[67];
 Float_t				convMVALikelihood[67];
 Float_t				convChi2[67];
 Float_t				convChi2Probability[67];
 Float_t				convTk1Dz[67];
 Float_t				convTk2Dz[67];
 Float_t				convTk1DzErr[67];
 Float_t				convTk2DzErr[67];
 Int_t				convCh1Ch2[67];
 Float_t				convTk1D0[67];
 Float_t				convTk1Pout[67];
 Float_t				convTk1Pin[67];
 Float_t				convTk2D0[67];
 Float_t				convTk2Pout[67];
 Float_t				convTk2Pin[67];
};
namespace OUT {
};
void InitINTree( TChain * tree) {

  tree->SetBranchAddress("nHLT", &IN::nHLT);
  tree->SetBranchAddress("nVtx", &IN::nVtx);
  tree->SetBranchAddress("nVtxBS", &IN::nVtxBS);
  tree->SetBranchAddress("nMC", &IN::nMC);
  tree->SetBranchAddress("nPUInfo", &IN::nPUInfo);
  tree->SetBranchAddress("nEle", &IN::nEle);
  tree->SetBranchAddress("nPho", &IN::nPho);
  tree->SetBranchAddress("nMu", &IN::nMu);
  tree->SetBranchAddress("nPFPho", &IN::nPFPho);
  tree->SetBranchAddress("nJet", &IN::nJet);
  tree->SetBranchAddress("nConv", &IN::nConv);
  tree->SetBranchAddress("nLowPtJet", &IN::nLowPtJet);
  tree->SetBranchAddress("run", &IN::run);
  tree->SetBranchAddress("event", &IN::event);
  tree->SetBranchAddress("lumis", &IN::lumis);
  tree->SetBranchAddress("isData", &IN::isData);
  tree->SetBranchAddress("HLT", &IN::HLT);
  tree->SetBranchAddress("HLTIndex", &IN::HLTIndex);
  tree->SetBranchAddress("bspotPos", &IN::bspotPos);
  tree->SetBranchAddress("vtx", &IN::vtx);
  tree->SetBranchAddress("IsVtxGood", &IN::IsVtxGood);
  tree->SetBranchAddress("nGoodVtx", &IN::nGoodVtx);
  tree->SetBranchAddress("vtxbs", &IN::vtxbs);
  tree->SetBranchAddress("pdf", &IN::pdf);
  tree->SetBranchAddress("pthat", &IN::pthat);
  tree->SetBranchAddress("processID", &IN::processID);
  tree->SetBranchAddress("mcPID", &IN::mcPID);
  tree->SetBranchAddress("mcVtx", &IN::mcVtx);
  tree->SetBranchAddress("mcPt", &IN::mcPt);
  tree->SetBranchAddress("mcEta", &IN::mcEta);
  tree->SetBranchAddress("mcPhi", &IN::mcPhi);
  tree->SetBranchAddress("mcE", &IN::mcE);
  tree->SetBranchAddress("mcGMomPID", &IN::mcGMomPID);
  tree->SetBranchAddress("mcMomPID", &IN::mcMomPID);
  tree->SetBranchAddress("mcMomPt", &IN::mcMomPt);
  tree->SetBranchAddress("mcMomMass", &IN::mcMomMass);
  tree->SetBranchAddress("mcMomEta", &IN::mcMomEta);
  tree->SetBranchAddress("mcMomPhi", &IN::mcMomPhi);
  tree->SetBranchAddress("mcIndex", &IN::mcIndex);
  tree->SetBranchAddress("mcDecayType", &IN::mcDecayType);
  tree->SetBranchAddress("mcParentage", &IN::mcParentage);
  tree->SetBranchAddress("mcStatus", &IN::mcStatus);
  tree->SetBranchAddress("genMET", &IN::genMET);
  tree->SetBranchAddress("genMETPhi", &IN::genMETPhi);
  tree->SetBranchAddress("nPU", &IN::nPU);
  tree->SetBranchAddress("puBX", &IN::puBX);
  tree->SetBranchAddress("puTrue", &IN::puTrue);
  tree->SetBranchAddress("pfMET", &IN::pfMET);
  tree->SetBranchAddress("pfMETPhi", &IN::pfMETPhi);
  tree->SetBranchAddress("pfMETsumEt", &IN::pfMETsumEt);
  tree->SetBranchAddress("pfMETmEtSig", &IN::pfMETmEtSig);
  tree->SetBranchAddress("pfMETSig", &IN::pfMETSig);
  tree->SetBranchAddress("recoPfMET", &IN::recoPfMET);
  tree->SetBranchAddress("recoPfMETPhi", &IN::recoPfMETPhi);
  tree->SetBranchAddress("recoPfMETsumEt", &IN::recoPfMETsumEt);
  tree->SetBranchAddress("recoPfMETmEtSig", &IN::recoPfMETmEtSig);
  tree->SetBranchAddress("recoPfMETSig", &IN::recoPfMETSig);
  tree->SetBranchAddress("trkMETxPV", &IN::trkMETxPV);
  tree->SetBranchAddress("trkMETyPV", &IN::trkMETyPV);
  tree->SetBranchAddress("trkMETPhiPV", &IN::trkMETPhiPV);
  tree->SetBranchAddress("trkMETPV", &IN::trkMETPV);
  tree->SetBranchAddress("trkMETx", &IN::trkMETx);
  tree->SetBranchAddress("trkMETy", &IN::trkMETy);
  tree->SetBranchAddress("trkMETPhi", &IN::trkMETPhi);
  tree->SetBranchAddress("trkMET", &IN::trkMET);
  tree->SetBranchAddress("metFilters", &IN::metFilters);
  tree->SetBranchAddress("eleTrg", &IN::eleTrg);
  tree->SetBranchAddress("eleClass", &IN::eleClass);
  tree->SetBranchAddress("eleIsEcalDriven", &IN::eleIsEcalDriven);
  tree->SetBranchAddress("eleCharge", &IN::eleCharge);
  tree->SetBranchAddress("eleEn", &IN::eleEn);
  tree->SetBranchAddress("eleEcalEn", &IN::eleEcalEn);
  tree->SetBranchAddress("eleSCRawEn", &IN::eleSCRawEn);
  tree->SetBranchAddress("eleSCEn", &IN::eleSCEn);
  tree->SetBranchAddress("eleESEn", &IN::eleESEn);
  tree->SetBranchAddress("elePt", &IN::elePt);
  tree->SetBranchAddress("eleEta", &IN::eleEta);
  tree->SetBranchAddress("elePhi", &IN::elePhi);
  tree->SetBranchAddress("eleEtaVtx", &IN::eleEtaVtx);
  tree->SetBranchAddress("elePhiVtx", &IN::elePhiVtx);
  tree->SetBranchAddress("eleEtVtx", &IN::eleEtVtx);
  tree->SetBranchAddress("eleSCEta", &IN::eleSCEta);
  tree->SetBranchAddress("eleSCPhi", &IN::eleSCPhi);
  tree->SetBranchAddress("eleSCEtaWidth", &IN::eleSCEtaWidth);
  tree->SetBranchAddress("eleSCPhiWidth", &IN::eleSCPhiWidth);
  tree->SetBranchAddress("eleVtx", &IN::eleVtx);
  tree->SetBranchAddress("eleD0", &IN::eleD0);
  tree->SetBranchAddress("eleDz", &IN::eleDz);
  tree->SetBranchAddress("eleD0GV", &IN::eleD0GV);
  tree->SetBranchAddress("eleDzGV", &IN::eleDzGV);
  tree->SetBranchAddress("eleD0Vtx", &IN::eleD0Vtx);
  tree->SetBranchAddress("eleDzVtx", &IN::eleDzVtx);
  tree->SetBranchAddress("eleHoverE", &IN::eleHoverE);
  tree->SetBranchAddress("eleHoverE12", &IN::eleHoverE12);
  tree->SetBranchAddress("eleEoverP", &IN::eleEoverP);
  tree->SetBranchAddress("elePin", &IN::elePin);
  tree->SetBranchAddress("elePout", &IN::elePout);
  tree->SetBranchAddress("eleTrkMomErr", &IN::eleTrkMomErr);
  tree->SetBranchAddress("eleBrem", &IN::eleBrem);
  tree->SetBranchAddress("eledEtaAtVtx", &IN::eledEtaAtVtx);
  tree->SetBranchAddress("eledPhiAtVtx", &IN::eledPhiAtVtx);
  tree->SetBranchAddress("eleSigmaIEtaIEta", &IN::eleSigmaIEtaIEta);
  tree->SetBranchAddress("eleSigmaIEtaIPhi", &IN::eleSigmaIEtaIPhi);
  tree->SetBranchAddress("eleSigmaIPhiIPhi", &IN::eleSigmaIPhiIPhi);
  tree->SetBranchAddress("eleEmax", &IN::eleEmax);
  tree->SetBranchAddress("eleE1x5", &IN::eleE1x5);
  tree->SetBranchAddress("eleE3x3", &IN::eleE3x3);
  tree->SetBranchAddress("eleE5x5", &IN::eleE5x5);
  tree->SetBranchAddress("eleE2x5Max", &IN::eleE2x5Max);
  tree->SetBranchAddress("eleRegrE", &IN::eleRegrE);
  tree->SetBranchAddress("eleRegrEerr", &IN::eleRegrEerr);
  tree->SetBranchAddress("elePhoRegrE", &IN::elePhoRegrE);
  tree->SetBranchAddress("elePhoRegrEerr", &IN::elePhoRegrEerr);
  tree->SetBranchAddress("eleSeedTime", &IN::eleSeedTime);
  tree->SetBranchAddress("eleRecoFlag", &IN::eleRecoFlag);
  tree->SetBranchAddress("elePos", &IN::elePos);
  tree->SetBranchAddress("eleGenIndex", &IN::eleGenIndex);
  tree->SetBranchAddress("eleGenGMomPID", &IN::eleGenGMomPID);
  tree->SetBranchAddress("eleGenMomPID", &IN::eleGenMomPID);
  tree->SetBranchAddress("eleGenMomPt", &IN::eleGenMomPt);
  tree->SetBranchAddress("eleIsoTrkDR03", &IN::eleIsoTrkDR03);
  tree->SetBranchAddress("eleIsoEcalDR03", &IN::eleIsoEcalDR03);
  tree->SetBranchAddress("eleIsoHcalDR03", &IN::eleIsoHcalDR03);
  tree->SetBranchAddress("eleIsoHcalDR0312", &IN::eleIsoHcalDR0312);
  tree->SetBranchAddress("eleIsoTrkDR04", &IN::eleIsoTrkDR04);
  tree->SetBranchAddress("eleIsoEcalDR04", &IN::eleIsoEcalDR04);
  tree->SetBranchAddress("eleIsoHcalDR04", &IN::eleIsoHcalDR04);
  tree->SetBranchAddress("eleIsoHcalDR0412", &IN::eleIsoHcalDR0412);
  tree->SetBranchAddress("eleModIsoTrk", &IN::eleModIsoTrk);
  tree->SetBranchAddress("eleModIsoEcal", &IN::eleModIsoEcal);
  tree->SetBranchAddress("eleModIsoHcal", &IN::eleModIsoHcal);
  tree->SetBranchAddress("eleMissHits", &IN::eleMissHits);
  tree->SetBranchAddress("eleConvDist", &IN::eleConvDist);
  tree->SetBranchAddress("eleConvDcot", &IN::eleConvDcot);
  tree->SetBranchAddress("eleConvVtxFit", &IN::eleConvVtxFit);
  tree->SetBranchAddress("eleIP3D", &IN::eleIP3D);
  tree->SetBranchAddress("eleIP3DErr", &IN::eleIP3DErr);
  tree->SetBranchAddress("eleIDMVANonTrig", &IN::eleIDMVANonTrig);
  tree->SetBranchAddress("eleIDMVATrig", &IN::eleIDMVATrig);
  tree->SetBranchAddress("eleIDMVATrigIDIso", &IN::eleIDMVATrigIDIso);
  tree->SetBranchAddress("elePFChIso03", &IN::elePFChIso03);
  tree->SetBranchAddress("elePFPhoIso03", &IN::elePFPhoIso03);
  tree->SetBranchAddress("elePFNeuIso03", &IN::elePFNeuIso03);
  tree->SetBranchAddress("elePFChIso04", &IN::elePFChIso04);
  tree->SetBranchAddress("elePFPhoIso04", &IN::elePFPhoIso04);
  tree->SetBranchAddress("elePFNeuIso04", &IN::elePFNeuIso04);
  tree->SetBranchAddress("eleESEffSigmaRR", &IN::eleESEffSigmaRR);
  tree->SetBranchAddress("phoTrg", &IN::phoTrg);
  tree->SetBranchAddress("phoTrgFilter", &IN::phoTrgFilter);
  tree->SetBranchAddress("phoIsPhoton", &IN::phoIsPhoton);
  tree->SetBranchAddress("phoSCPos", &IN::phoSCPos);
  tree->SetBranchAddress("phoCaloPos", &IN::phoCaloPos);
  tree->SetBranchAddress("phoE", &IN::phoE);
  tree->SetBranchAddress("phoEt", &IN::phoEt);
  tree->SetBranchAddress("phoEta", &IN::phoEta);
  tree->SetBranchAddress("phoVtx", &IN::phoVtx);
  tree->SetBranchAddress("phoPhi", &IN::phoPhi);
  tree->SetBranchAddress("phoR9", &IN::phoR9);
  tree->SetBranchAddress("phoTrkIsoHollowDR03", &IN::phoTrkIsoHollowDR03);
  tree->SetBranchAddress("phoEcalIsoDR03", &IN::phoEcalIsoDR03);
  tree->SetBranchAddress("phoHcalIsoDR03", &IN::phoHcalIsoDR03);
  tree->SetBranchAddress("phoHcalIsoDR0312", &IN::phoHcalIsoDR0312);
  tree->SetBranchAddress("phoTrkIsoHollowDR04", &IN::phoTrkIsoHollowDR04);
  tree->SetBranchAddress("phoCiCTrkIsoDR03", &IN::phoCiCTrkIsoDR03);
  tree->SetBranchAddress("phoCiCTrkIsoDR04", &IN::phoCiCTrkIsoDR04);
  tree->SetBranchAddress("phoCiCdRtoTrk", &IN::phoCiCdRtoTrk);
  tree->SetBranchAddress("phoEcalIsoDR04", &IN::phoEcalIsoDR04);
  tree->SetBranchAddress("phoHcalIsoDR04", &IN::phoHcalIsoDR04);
  tree->SetBranchAddress("phoHcalIsoDR0412", &IN::phoHcalIsoDR0412);
  tree->SetBranchAddress("phoHoverE", &IN::phoHoverE);
  tree->SetBranchAddress("phoHoverE12", &IN::phoHoverE12);
  tree->SetBranchAddress("phoEleVeto", &IN::phoEleVeto);
  tree->SetBranchAddress("phoSigmaIEtaIEta", &IN::phoSigmaIEtaIEta);
  tree->SetBranchAddress("phoSigmaIEtaIPhi", &IN::phoSigmaIEtaIPhi);
  tree->SetBranchAddress("phoSigmaIPhiIPhi", &IN::phoSigmaIPhiIPhi);
  tree->SetBranchAddress("phoCiCPF4phopfIso03", &IN::phoCiCPF4phopfIso03);
  tree->SetBranchAddress("phoCiCPF4phopfIso04", &IN::phoCiCPF4phopfIso04);
  tree->SetBranchAddress("phoCiCPF4chgpfIso02", &IN::phoCiCPF4chgpfIso02);
  tree->SetBranchAddress("phoCiCPF4chgpfIso03", &IN::phoCiCPF4chgpfIso03);
  tree->SetBranchAddress("phoCiCPF4chgpfIso04", &IN::phoCiCPF4chgpfIso04);
  tree->SetBranchAddress("phoEmax", &IN::phoEmax);
  tree->SetBranchAddress("phoE3x3", &IN::phoE3x3);
  tree->SetBranchAddress("phoE3x1", &IN::phoE3x1);
  tree->SetBranchAddress("phoE1x3", &IN::phoE1x3);
  tree->SetBranchAddress("phoE5x5", &IN::phoE5x5);
  tree->SetBranchAddress("phoE1x5", &IN::phoE1x5);
  tree->SetBranchAddress("phoE2x2", &IN::phoE2x2);
  tree->SetBranchAddress("phoE2x5Max", &IN::phoE2x5Max);
  tree->SetBranchAddress("phoPFChIso", &IN::phoPFChIso);
  tree->SetBranchAddress("phoPFPhoIso", &IN::phoPFPhoIso);
  tree->SetBranchAddress("phoPFNeuIso", &IN::phoPFNeuIso);
  tree->SetBranchAddress("phoSCRChIso", &IN::phoSCRChIso);
  tree->SetBranchAddress("phoSCRPhoIso", &IN::phoSCRPhoIso);
  tree->SetBranchAddress("phoSCRNeuIso", &IN::phoSCRNeuIso);
  tree->SetBranchAddress("phoRegrE", &IN::phoRegrE);
  tree->SetBranchAddress("phoRegrEerr", &IN::phoRegrEerr);
  tree->SetBranchAddress("phoSeedTime", &IN::phoSeedTime);
  tree->SetBranchAddress("phoSeedDetId1", &IN::phoSeedDetId1);
  tree->SetBranchAddress("phoSeedDetId2", &IN::phoSeedDetId2);
  tree->SetBranchAddress("phoLICTD", &IN::phoLICTD);
  tree->SetBranchAddress("phoRecoFlag", &IN::phoRecoFlag);
  tree->SetBranchAddress("phoPos", &IN::phoPos);
  tree->SetBranchAddress("phoGenIndex", &IN::phoGenIndex);
  tree->SetBranchAddress("phoGenGMomPID", &IN::phoGenGMomPID);
  tree->SetBranchAddress("phoGenMomPID", &IN::phoGenMomPID);
  tree->SetBranchAddress("phoGenMomPt", &IN::phoGenMomPt);
  tree->SetBranchAddress("phoSCE", &IN::phoSCE);
  tree->SetBranchAddress("phoSCRawE", &IN::phoSCRawE);
  tree->SetBranchAddress("phoESEn", &IN::phoESEn);
  tree->SetBranchAddress("phoSCEt", &IN::phoSCEt);
  tree->SetBranchAddress("phoSCEta", &IN::phoSCEta);
  tree->SetBranchAddress("phoSCPhi", &IN::phoSCPhi);
  tree->SetBranchAddress("phoSCEtaWidth", &IN::phoSCEtaWidth);
  tree->SetBranchAddress("phoSCPhiWidth", &IN::phoSCPhiWidth);
  tree->SetBranchAddress("phoSCBrem", &IN::phoSCBrem);
  tree->SetBranchAddress("phoOverlap", &IN::phoOverlap);
  tree->SetBranchAddress("phohasPixelSeed", &IN::phohasPixelSeed);
  tree->SetBranchAddress("pho_hasConvPf", &IN::pho_hasConvPf);
  tree->SetBranchAddress("pho_hasSLConvPf", &IN::pho_hasSLConvPf);
  tree->SetBranchAddress("pho_pfconvVtxZ", &IN::pho_pfconvVtxZ);
  tree->SetBranchAddress("pho_pfconvVtxZErr", &IN::pho_pfconvVtxZErr);
  tree->SetBranchAddress("pho_nSLConv", &IN::pho_nSLConv);
  tree->SetBranchAddress("pho_pfSLConvPos", &IN::pho_pfSLConvPos);
  tree->SetBranchAddress("pho_pfSLConvVtxZ", &IN::pho_pfSLConvVtxZ);
  tree->SetBranchAddress("phoIsConv", &IN::phoIsConv);
  tree->SetBranchAddress("phoNConv", &IN::phoNConv);
  tree->SetBranchAddress("phoConvInvMass", &IN::phoConvInvMass);
  tree->SetBranchAddress("phoConvCotTheta", &IN::phoConvCotTheta);
  tree->SetBranchAddress("phoConvEoverP", &IN::phoConvEoverP);
  tree->SetBranchAddress("phoConvZofPVfromTrks", &IN::phoConvZofPVfromTrks);
  tree->SetBranchAddress("phoConvMinDist", &IN::phoConvMinDist);
  tree->SetBranchAddress("phoConvdPhiAtVtx", &IN::phoConvdPhiAtVtx);
  tree->SetBranchAddress("phoConvdPhiAtCalo", &IN::phoConvdPhiAtCalo);
  tree->SetBranchAddress("phoConvdEtaAtCalo", &IN::phoConvdEtaAtCalo);
  tree->SetBranchAddress("phoConvTrkd0", &IN::phoConvTrkd0);
  tree->SetBranchAddress("phoConvTrkPin", &IN::phoConvTrkPin);
  tree->SetBranchAddress("phoConvTrkPout", &IN::phoConvTrkPout);
  tree->SetBranchAddress("phoConvTrkdz", &IN::phoConvTrkdz);
  tree->SetBranchAddress("phoConvTrkdzErr", &IN::phoConvTrkdzErr);
  tree->SetBranchAddress("phoConvChi2", &IN::phoConvChi2);
  tree->SetBranchAddress("phoConvChi2Prob", &IN::phoConvChi2Prob);
  tree->SetBranchAddress("phoConvNTrks", &IN::phoConvNTrks);
  tree->SetBranchAddress("phoConvCharge", &IN::phoConvCharge);
  tree->SetBranchAddress("phoConvValidVtx", &IN::phoConvValidVtx);
  tree->SetBranchAddress("phoConvLikeLihood", &IN::phoConvLikeLihood);
  tree->SetBranchAddress("phoConvP4", &IN::phoConvP4);
  tree->SetBranchAddress("phoConvVtx", &IN::phoConvVtx);
  tree->SetBranchAddress("phoConvVtxErr", &IN::phoConvVtxErr);
  tree->SetBranchAddress("phoConvPairMomentum", &IN::phoConvPairMomentum);
  tree->SetBranchAddress("phoConvRefittedMomentum", &IN::phoConvRefittedMomentum);
  tree->SetBranchAddress("SingleLegConv", &IN::SingleLegConv);
  tree->SetBranchAddress("phoPFConvVtx", &IN::phoPFConvVtx);
  tree->SetBranchAddress("phoPFConvMom", &IN::phoPFConvMom);
  tree->SetBranchAddress("phoESEffSigmaRR", &IN::phoESEffSigmaRR);
  tree->SetBranchAddress("muTrg", &IN::muTrg);
  tree->SetBranchAddress("muEta", &IN::muEta);
  tree->SetBranchAddress("muPhi", &IN::muPhi);
  tree->SetBranchAddress("muCharge", &IN::muCharge);
  tree->SetBranchAddress("muPt", &IN::muPt);
  tree->SetBranchAddress("muPz", &IN::muPz);
  tree->SetBranchAddress("muVtx", &IN::muVtx);
  tree->SetBranchAddress("muVtxGlb", &IN::muVtxGlb);
  tree->SetBranchAddress("muGenIndex", &IN::muGenIndex);
  tree->SetBranchAddress("mucktPt", &IN::mucktPt);
  tree->SetBranchAddress("mucktPtErr", &IN::mucktPtErr);
  tree->SetBranchAddress("mucktEta", &IN::mucktEta);
  tree->SetBranchAddress("mucktPhi", &IN::mucktPhi);
  tree->SetBranchAddress("mucktdxy", &IN::mucktdxy);
  tree->SetBranchAddress("mucktdz", &IN::mucktdz);
  tree->SetBranchAddress("muIsoTrk", &IN::muIsoTrk);
  tree->SetBranchAddress("muIsoCalo", &IN::muIsoCalo);
  tree->SetBranchAddress("muIsoEcal", &IN::muIsoEcal);
  tree->SetBranchAddress("muIsoHcal", &IN::muIsoHcal);
  tree->SetBranchAddress("muChi2NDF", &IN::muChi2NDF);
  tree->SetBranchAddress("muInnerChi2NDF", &IN::muInnerChi2NDF);
  tree->SetBranchAddress("muPFIsoR04_CH", &IN::muPFIsoR04_CH);
  tree->SetBranchAddress("muPFIsoR04_NH", &IN::muPFIsoR04_NH);
  tree->SetBranchAddress("muPFIsoR04_Pho", &IN::muPFIsoR04_Pho);
  tree->SetBranchAddress("muPFIsoR04_PU", &IN::muPFIsoR04_PU);
  tree->SetBranchAddress("muPFIsoR04_CPart", &IN::muPFIsoR04_CPart);
  tree->SetBranchAddress("muPFIsoR04_NHHT", &IN::muPFIsoR04_NHHT);
  tree->SetBranchAddress("muPFIsoR04_PhoHT", &IN::muPFIsoR04_PhoHT);
  tree->SetBranchAddress("muPFIsoR03_CH", &IN::muPFIsoR03_CH);
  tree->SetBranchAddress("muPFIsoR03_NH", &IN::muPFIsoR03_NH);
  tree->SetBranchAddress("muPFIsoR03_Pho", &IN::muPFIsoR03_Pho);
  tree->SetBranchAddress("muPFIsoR03_PU", &IN::muPFIsoR03_PU);
  tree->SetBranchAddress("muPFIsoR03_CPart", &IN::muPFIsoR03_CPart);
  tree->SetBranchAddress("muPFIsoR03_NHHT", &IN::muPFIsoR03_NHHT);
  tree->SetBranchAddress("muPFIsoR03_PhoHT", &IN::muPFIsoR03_PhoHT);
  tree->SetBranchAddress("muType", &IN::muType);
  tree->SetBranchAddress("muD0", &IN::muD0);
  tree->SetBranchAddress("muDz", &IN::muDz);
  tree->SetBranchAddress("muD0GV", &IN::muD0GV);
  tree->SetBranchAddress("muDzGV", &IN::muDzGV);
  tree->SetBranchAddress("muD0Vtx", &IN::muD0Vtx);
  tree->SetBranchAddress("muDzVtx", &IN::muDzVtx);
  tree->SetBranchAddress("muInnerD0", &IN::muInnerD0);
  tree->SetBranchAddress("muInnerDz", &IN::muInnerDz);
  tree->SetBranchAddress("muInnerD0GV", &IN::muInnerD0GV);
  tree->SetBranchAddress("muInnerDzGV", &IN::muInnerDzGV);
  tree->SetBranchAddress("muInnerPt", &IN::muInnerPt);
  tree->SetBranchAddress("muInnerPtErr", &IN::muInnerPtErr);
  tree->SetBranchAddress("muNumberOfValidTrkLayers", &IN::muNumberOfValidTrkLayers);
  tree->SetBranchAddress("muNumberOfValidTrkHits", &IN::muNumberOfValidTrkHits);
  tree->SetBranchAddress("muNumberOfValidPixelLayers", &IN::muNumberOfValidPixelLayers);
  tree->SetBranchAddress("muNumberOfValidPixelHits", &IN::muNumberOfValidPixelHits);
  tree->SetBranchAddress("muNumberOfValidMuonHits", &IN::muNumberOfValidMuonHits);
  tree->SetBranchAddress("muStations", &IN::muStations);
  tree->SetBranchAddress("muChambers", &IN::muChambers);
  tree->SetBranchAddress("muIP3D", &IN::muIP3D);
  tree->SetBranchAddress("muIP3DErr", &IN::muIP3DErr);
  tree->SetBranchAddress("PFPhoEt", &IN::PFPhoEt);
  tree->SetBranchAddress("PFPhoEta", &IN::PFPhoEta);
  tree->SetBranchAddress("PFPhoPhi", &IN::PFPhoPhi);
  tree->SetBranchAddress("PFPhoType", &IN::PFPhoType);
  tree->SetBranchAddress("PFPhoIso", &IN::PFPhoIso);
  tree->SetBranchAddress("rho25", &IN::rho25);
  tree->SetBranchAddress("rho25_neu", &IN::rho25_neu);
  tree->SetBranchAddress("rho25_muPFiso", &IN::rho25_muPFiso);
  tree->SetBranchAddress("rho25_elePFiso", &IN::rho25_elePFiso);
  tree->SetBranchAddress("rho2011", &IN::rho2011);
  tree->SetBranchAddress("rho2012", &IN::rho2012);
  tree->SetBranchAddress("jetTrg", &IN::jetTrg);
  tree->SetBranchAddress("jetEn", &IN::jetEn);
  tree->SetBranchAddress("jetPt", &IN::jetPt);
  tree->SetBranchAddress("jetEta", &IN::jetEta);
  tree->SetBranchAddress("jetPhi", &IN::jetPhi);
  tree->SetBranchAddress("jetCharge", &IN::jetCharge);
  tree->SetBranchAddress("jetEt", &IN::jetEt);
  tree->SetBranchAddress("jetRawPt", &IN::jetRawPt);
  tree->SetBranchAddress("jetRawEn", &IN::jetRawEn);
  tree->SetBranchAddress("jetArea", &IN::jetArea);
  tree->SetBranchAddress("jetCHF", &IN::jetCHF);
  tree->SetBranchAddress("jetNHF", &IN::jetNHF);
  tree->SetBranchAddress("jetCEF", &IN::jetCEF);
  tree->SetBranchAddress("jetNEF", &IN::jetNEF);
  tree->SetBranchAddress("jetNCH", &IN::jetNCH);
  tree->SetBranchAddress("jetHFHAE", &IN::jetHFHAE);
  tree->SetBranchAddress("jetHFEME", &IN::jetHFEME);
  tree->SetBranchAddress("jetNConstituents", &IN::jetNConstituents);
  tree->SetBranchAddress("jetCombinedSecondaryVtxBJetTags", &IN::jetCombinedSecondaryVtxBJetTags);
  tree->SetBranchAddress("jetCombinedSecondaryVtxMVABJetTags", &IN::jetCombinedSecondaryVtxMVABJetTags);
  tree->SetBranchAddress("jetJetProbabilityBJetTags", &IN::jetJetProbabilityBJetTags);
  tree->SetBranchAddress("jetJetBProbabilityBJetTags", &IN::jetJetBProbabilityBJetTags);
  tree->SetBranchAddress("jetTrackCountingHighPurBJetTags", &IN::jetTrackCountingHighPurBJetTags);
  tree->SetBranchAddress("jetBetaStar", &IN::jetBetaStar);
  tree->SetBranchAddress("jetPFLooseId", &IN::jetPFLooseId);
  tree->SetBranchAddress("jetDRMean", &IN::jetDRMean);
  tree->SetBranchAddress("jetDR2Mean", &IN::jetDR2Mean);
  tree->SetBranchAddress("jetDZ", &IN::jetDZ);
  tree->SetBranchAddress("jetFrac01", &IN::jetFrac01);
  tree->SetBranchAddress("jetFrac02", &IN::jetFrac02);
  tree->SetBranchAddress("jetFrac03", &IN::jetFrac03);
  tree->SetBranchAddress("jetFrac04", &IN::jetFrac04);
  tree->SetBranchAddress("jetFrac05", &IN::jetFrac05);
  tree->SetBranchAddress("jetFrac06", &IN::jetFrac06);
  tree->SetBranchAddress("jetFrac07", &IN::jetFrac07);
  tree->SetBranchAddress("jetBeta", &IN::jetBeta);
  tree->SetBranchAddress("jetBetaStarCMG", &IN::jetBetaStarCMG);
  tree->SetBranchAddress("jetBetaStarClassic", &IN::jetBetaStarClassic);
  tree->SetBranchAddress("jetBetaExt", &IN::jetBetaExt);
  tree->SetBranchAddress("jetNNeutrals", &IN::jetNNeutrals);
  tree->SetBranchAddress("jetNCharged", &IN::jetNCharged);
  tree->SetBranchAddress("jetMVAs", &IN::jetMVAs);
  tree->SetBranchAddress("jetWPLevels", &IN::jetWPLevels);
  tree->SetBranchAddress("jetMt", &IN::jetMt);
  tree->SetBranchAddress("jetJECUnc", &IN::jetJECUnc);
  tree->SetBranchAddress("jetLeadTrackPt", &IN::jetLeadTrackPt);
  tree->SetBranchAddress("jetVtxPt", &IN::jetVtxPt);
  tree->SetBranchAddress("jetVtxMass", &IN::jetVtxMass);
  tree->SetBranchAddress("jetVtx3dL", &IN::jetVtx3dL);
  tree->SetBranchAddress("jetVtx3deL", &IN::jetVtx3deL);
  tree->SetBranchAddress("jetSoftLeptPt", &IN::jetSoftLeptPt);
  tree->SetBranchAddress("jetSoftLeptPtRel", &IN::jetSoftLeptPtRel);
  tree->SetBranchAddress("jetSoftLeptdR", &IN::jetSoftLeptdR);
  tree->SetBranchAddress("jetSoftLeptIdlooseMu", &IN::jetSoftLeptIdlooseMu);
  tree->SetBranchAddress("jetSoftLeptIdEle95", &IN::jetSoftLeptIdEle95);
  tree->SetBranchAddress("jetDPhiMETJet", &IN::jetDPhiMETJet);
  tree->SetBranchAddress("jetPuJetIdL", &IN::jetPuJetIdL);
  tree->SetBranchAddress("jetPuJetIdM", &IN::jetPuJetIdM);
  tree->SetBranchAddress("jetPuJetIdT", &IN::jetPuJetIdT);
  tree->SetBranchAddress("jetPartonID", &IN::jetPartonID);
  tree->SetBranchAddress("jetGenJetIndex", &IN::jetGenJetIndex);
  tree->SetBranchAddress("jetGenJetEn", &IN::jetGenJetEn);
  tree->SetBranchAddress("jetGenJetPt", &IN::jetGenJetPt);
  tree->SetBranchAddress("jetGenJetEta", &IN::jetGenJetEta);
  tree->SetBranchAddress("jetGenJetPhi", &IN::jetGenJetPhi);
  tree->SetBranchAddress("jetGenPartonID", &IN::jetGenPartonID);
  tree->SetBranchAddress("jetGenEn", &IN::jetGenEn);
  tree->SetBranchAddress("jetGenPt", &IN::jetGenPt);
  tree->SetBranchAddress("jetGenEta", &IN::jetGenEta);
  tree->SetBranchAddress("jetGenPhi", &IN::jetGenPhi);
  tree->SetBranchAddress("convVtx", &IN::convVtx);
  tree->SetBranchAddress("convVtxErr", &IN::convVtxErr);
  tree->SetBranchAddress("convPairMomentum", &IN::convPairMomentum);
  tree->SetBranchAddress("convRefittedMomentum", &IN::convRefittedMomentum);
  tree->SetBranchAddress("convNTracks", &IN::convNTracks);
  tree->SetBranchAddress("convPairInvMass", &IN::convPairInvMass);
  tree->SetBranchAddress("convPairCotThetaSep", &IN::convPairCotThetaSep);
  tree->SetBranchAddress("convEoverP", &IN::convEoverP);
  tree->SetBranchAddress("convDistOfMinApproach", &IN::convDistOfMinApproach);
  tree->SetBranchAddress("convDPhiTrksAtVtx", &IN::convDPhiTrksAtVtx);
  tree->SetBranchAddress("convDPhiTrksAtEcal", &IN::convDPhiTrksAtEcal);
  tree->SetBranchAddress("convDEtaTrksAtEcal", &IN::convDEtaTrksAtEcal);
  tree->SetBranchAddress("convDxy", &IN::convDxy);
  tree->SetBranchAddress("convDz", &IN::convDz);
  tree->SetBranchAddress("convLxy", &IN::convLxy);
  tree->SetBranchAddress("convLz", &IN::convLz);
  tree->SetBranchAddress("convZofPrimVtxFromTrks", &IN::convZofPrimVtxFromTrks);
  tree->SetBranchAddress("convNHitsBeforeVtx", &IN::convNHitsBeforeVtx);
  tree->SetBranchAddress("convNSharedHits", &IN::convNSharedHits);
  tree->SetBranchAddress("convValidVtx", &IN::convValidVtx);
  tree->SetBranchAddress("convMVALikelihood", &IN::convMVALikelihood);
  tree->SetBranchAddress("convChi2", &IN::convChi2);
  tree->SetBranchAddress("convChi2Probability", &IN::convChi2Probability);
  tree->SetBranchAddress("convTk1Dz", &IN::convTk1Dz);
  tree->SetBranchAddress("convTk2Dz", &IN::convTk2Dz);
  tree->SetBranchAddress("convTk1DzErr", &IN::convTk1DzErr);
  tree->SetBranchAddress("convTk2DzErr", &IN::convTk2DzErr);
  tree->SetBranchAddress("convCh1Ch2", &IN::convCh1Ch2);
  tree->SetBranchAddress("convTk1D0", &IN::convTk1D0);
  tree->SetBranchAddress("convTk1Pout", &IN::convTk1Pout);
  tree->SetBranchAddress("convTk1Pin", &IN::convTk1Pin);
  tree->SetBranchAddress("convTk2D0", &IN::convTk2D0);
  tree->SetBranchAddress("convTk2Pout", &IN::convTk2Pout);
  tree->SetBranchAddress("convTk2Pin", &IN::convTk2Pin);
};

void InitOUTTree( TTree * tree ) {
}
void CopyInputVarsToOutput() {
}
