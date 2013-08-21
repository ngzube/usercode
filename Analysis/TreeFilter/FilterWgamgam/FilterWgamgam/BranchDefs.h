#ifndef BRANCHDEFS_H
#define BRANCHDEFS_H
#include "TTree.h"
#include <vector>
//Define variables as extern below and declare them in the .cxx file to avoid multiple definitions
namespace IN {
 extern Int_t				nConv;
 extern Int_t				nLowPtJet;
 extern Int_t				nJet;
 extern Int_t				nPFPho;
 extern Int_t				nMu;
 extern Int_t				nPho;
 extern Int_t				nEle;
 extern Int_t				nPUInfo;
 extern Int_t				nMC;
 extern Int_t				nVtxBS;
 extern Int_t				nVtx;
 extern Int_t				nHLT;
 extern Int_t				run;
 extern Long64_t				event;
 extern Int_t				lumis;
 extern Bool_t				isData;
 extern Int_t				HLT[444];
 extern Int_t				HLTIndex[70];
 extern Float_t				bspotPos[3];
 extern Float_t				vtx[64][3];
 extern Int_t				IsVtxGood;
 extern Int_t				nGoodVtx;
 extern Float_t				vtxbs[64][3];
 extern Float_t				pdf[7];
 extern Float_t				pthat;
 extern Float_t				processID;
 extern Int_t				mcPID[138];
 extern Float_t				mcVtx[138][3];
 extern Float_t				mcPt[138];
 extern Float_t				mcMass[138];
 extern Float_t				mcEta[138];
 extern Float_t				mcPhi[138];
 extern Float_t				mcE[138];
 extern Float_t				mcEt[138];
 extern Int_t				mcGMomPID[138];
 extern Int_t				mcMomPID[138];
 extern Float_t				mcMomPt[138];
 extern Float_t				mcMomMass[138];
 extern Float_t				mcMomEta[138];
 extern Float_t				mcMomPhi[138];
 extern Int_t				mcIndex[138];
 extern Int_t				mcDecayType[138];
 extern Int_t				mcParentage[138];
 extern Int_t				mcStatus[138];
 extern Float_t				genMET;
 extern Float_t				genMETPhi;
 extern Int_t				nPU[4];
 extern Int_t				puBX[4];
 extern Float_t				puTrue[4];
 extern Float_t				pfMET;
 extern Float_t				pfMETPhi;
 extern Float_t				pfMETsumEt;
 extern Float_t				pfMETmEtSig;
 extern Float_t				pfMETSig;
 extern Float_t				recoPfMET;
 extern Float_t				recoPfMETPhi;
 extern Float_t				recoPfMETsumEt;
 extern Float_t				recoPfMETmEtSig;
 extern Float_t				recoPfMETSig;
 extern Float_t				trkMETxPV;
 extern Float_t				trkMETyPV;
 extern Float_t				trkMETPhiPV;
 extern Float_t				trkMETPV;
 extern Float_t				trkMETx[64];
 extern Float_t				trkMETy[64];
 extern Float_t				trkMETPhi[64];
 extern Float_t				trkMET[64];
 extern Int_t				metFilters[10];
 extern Int_t				eleTrg[13][16];
 extern Int_t				eleClass[13];
 extern Int_t				eleIsEcalDriven[13];
 extern Int_t				eleCharge[13];
 extern Float_t				eleEn[13];
 extern Float_t				eleEcalEn[13];
 extern Float_t				eleSCRawEn[13];
 extern Float_t				eleSCEn[13];
 extern Float_t				eleESEn[13];
 extern Float_t				elePt[13];
 extern Float_t				eleEta[13];
 extern Float_t				elePhi[13];
 extern Float_t				eleEtaVtx[13][100];
 extern Float_t				elePhiVtx[13][100];
 extern Float_t				eleEtVtx[13][100];
 extern Float_t				eleSCEta[13];
 extern Float_t				eleSCPhi[13];
 extern Float_t				eleSCEtaWidth[13];
 extern Float_t				eleSCPhiWidth[13];
 extern Float_t				eleVtx[13][3];
 extern Float_t				eleD0[13];
 extern Float_t				eleDz[13];
 extern Float_t				eleD0GV[13];
 extern Float_t				eleDzGV[13];
 extern Float_t				eleD0Vtx[13][100];
 extern Float_t				eleDzVtx[13][100];
 extern Float_t				eleHoverE[13];
 extern Float_t				eleHoverE12[13];
 extern Float_t				eleEoverP[13];
 extern Float_t				elePin[13];
 extern Float_t				elePout[13];
 extern Float_t				eleTrkMomErr[13];
 extern Float_t				eleBrem[13];
 extern Float_t				eledEtaAtVtx[13];
 extern Float_t				eledPhiAtVtx[13];
 extern Float_t				eleSigmaIEtaIEta[13];
 extern Float_t				eleSigmaIEtaIPhi[13];
 extern Float_t				eleSigmaIPhiIPhi[13];
 extern Float_t				eleEmax[13];
 extern Float_t				eleE1x5[13];
 extern Float_t				eleE3x3[13];
 extern Float_t				eleE5x5[13];
 extern Float_t				eleE2x5Max[13];
 extern Float_t				eleRegrE[13];
 extern Float_t				eleRegrEerr[13];
 extern Float_t				elePhoRegrE[13];
 extern Float_t				elePhoRegrEerr[13];
 extern Float_t				eleSeedTime[13];
 extern Int_t				eleRecoFlag[13];
 extern Int_t				elePos[13];
 extern Int_t				eleGenIndex[13];
 extern Int_t				eleGenGMomPID[13];
 extern Int_t				eleGenMomPID[13];
 extern Float_t				eleGenMomPt[13];
 extern Float_t				eleIsoTrkDR03[13];
 extern Float_t				eleIsoEcalDR03[13];
 extern Float_t				eleIsoHcalDR03[13];
 extern Float_t				eleIsoHcalDR0312[13];
 extern Float_t				eleIsoTrkDR04[13];
 extern Float_t				eleIsoEcalDR04[13];
 extern Float_t				eleIsoHcalDR04[13];
 extern Float_t				eleIsoHcalDR0412[13];
 extern Float_t				eleModIsoTrk[13];
 extern Float_t				eleModIsoEcal[13];
 extern Float_t				eleModIsoHcal[13];
 extern Int_t				eleMissHits[13];
 extern Float_t				eleConvDist[13];
 extern Float_t				eleConvDcot[13];
 extern Int_t				eleConvVtxFit[13];
 extern Float_t				eleIP3D[13];
 extern Float_t				eleIP3DErr[13];
 extern Float_t				eleIDMVANonTrig[13];
 extern Float_t				eleIDMVATrig[13];
 extern Float_t				eleIDMVATrigIDIso[13];
 extern Float_t				elePFChIso03[13];
 extern Float_t				elePFPhoIso03[13];
 extern Float_t				elePFNeuIso03[13];
 extern Float_t				elePFChIso04[13];
 extern Float_t				elePFPhoIso04[13];
 extern Float_t				elePFNeuIso04[13];
 extern Float_t				eleESEffSigmaRR[13][3];
 extern Int_t				phoTrg[13][8];
 extern Int_t				phoTrgFilter[13][50];
 extern Bool_t				phoIsPhoton[13];
 extern Float_t				phoSCPos[13][3];
 extern Float_t				phoCaloPos[13][3];
 extern Float_t				phoE[13];
 extern Float_t				phoEt[13];
 extern Float_t				phoEta[13];
 extern Float_t				phoVtx[13][3];
 extern Float_t				phoPhi[13];
 extern Float_t				phoEtVtx[13][100];
 extern Float_t				phoEtaVtx[13][100];
 extern Float_t				phoPhiVtx[13][100];
 extern Float_t				phoR9[13];
 extern Float_t				phoTrkIsoHollowDR03[13];
 extern Float_t				phoEcalIsoDR03[13];
 extern Float_t				phoHcalIsoDR03[13];
 extern Float_t				phoHcalIsoDR0312[13];
 extern Float_t				phoTrkIsoHollowDR04[13];
 extern Float_t				phoCiCTrkIsoDR03[13][100];
 extern Float_t				phoCiCTrkIsoDR04[13][100];
 extern Float_t				phoCiCdRtoTrk[13];
 extern Float_t				phoEcalIsoDR04[13];
 extern Float_t				phoHcalIsoDR04[13];
 extern Float_t				phoHcalIsoDR0412[13];
 extern Float_t				phoHoverE[13];
 extern Float_t				phoHoverE12[13];
 extern Int_t				phoEleVeto[13];
 extern Float_t				phoSigmaIEtaIEta[13];
 extern Float_t				phoSigmaIEtaIPhi[13];
 extern Float_t				phoSigmaIPhiIPhi[13];
 extern Float_t				phoCiCPF4phopfIso03[13];
 extern Float_t				phoCiCPF4phopfIso04[13];
 extern Float_t				phoCiCPF4chgpfIso02[13][100];
 extern Float_t				phoCiCPF4chgpfIso03[13][100];
 extern Float_t				phoCiCPF4chgpfIso04[13][100];
 extern Float_t				phoEmax[13];
 extern Float_t				phoE3x3[13];
 extern Float_t				phoE3x1[13];
 extern Float_t				phoE1x3[13];
 extern Float_t				phoE5x5[13];
 extern Float_t				phoE1x5[13];
 extern Float_t				phoE2x2[13];
 extern Float_t				phoE2x5Max[13];
 extern Float_t				phoPFChIso[13];
 extern Float_t				phoPFPhoIso[13];
 extern Float_t				phoPFNeuIso[13];
 extern Float_t				phoSCRChIso[13];
 extern Float_t				phoSCRPhoIso[13];
 extern Float_t				phoSCRNeuIso[13];
 extern Float_t				phoRegrE[13];
 extern Float_t				phoRegrEerr[13];
 extern Float_t				phoSeedTime[13];
 extern Int_t				phoSeedDetId1[13];
 extern Int_t				phoSeedDetId2[13];
 extern Float_t				phoLICTD[13];
 extern Int_t				phoRecoFlag[13];
 extern Int_t				phoPos[13];
 extern Int_t				phoGenIndex[13];
 extern Int_t				phoGenGMomPID[13];
 extern Int_t				phoGenMomPID[13];
 extern Float_t				phoGenMomPt[13];
 extern Float_t				phoSCE[13];
 extern Float_t				phoSCRawE[13];
 extern Float_t				phoESEn[13];
 extern Float_t				phoSCEt[13];
 extern Float_t				phoSCEta[13];
 extern Float_t				phoSCPhi[13];
 extern Float_t				phoSCEtaWidth[13];
 extern Float_t				phoSCPhiWidth[13];
 extern Float_t				phoSCBrem[13];
 extern Int_t				phoOverlap[13];
 extern Int_t				phohasPixelSeed[13];
 extern Int_t				pho_hasConvPf[13];
 extern Int_t				pho_hasSLConvPf[13];
 extern Float_t				pho_pfconvVtxZ[13];
 extern Float_t				pho_pfconvVtxZErr[13];
 extern Int_t				pho_nSLConv[13];
 extern Float_t				pho_pfSLConvPos[13][20][3];
 extern Float_t				pho_pfSLConvVtxZ[13][20];
 extern Int_t				phoIsConv[13];
 extern Int_t				phoNConv[13];
 extern Float_t				phoConvInvMass[13];
 extern Float_t				phoConvCotTheta[13];
 extern Float_t				phoConvEoverP[13];
 extern Float_t				phoConvZofPVfromTrks[13];
 extern Float_t				phoConvMinDist[13];
 extern Float_t				phoConvdPhiAtVtx[13];
 extern Float_t				phoConvdPhiAtCalo[13];
 extern Float_t				phoConvdEtaAtCalo[13];
 extern Float_t				phoConvTrkd0[13][2];
 extern Float_t				phoConvTrkPin[13][2];
 extern Float_t				phoConvTrkPout[13][2];
 extern Float_t				phoConvTrkdz[13][2];
 extern Float_t				phoConvTrkdzErr[13][2];
 extern Float_t				phoConvChi2[13];
 extern Float_t				phoConvChi2Prob[13];
 extern Int_t				phoConvNTrks[13];
 extern Float_t				phoConvCharge[13][2];
 extern Float_t				phoConvValidVtx[13];
 extern Float_t				phoConvLikeLihood[13];
 extern Float_t				phoConvP4[13][4];
 extern Float_t				phoConvVtx[13][3];
 extern Float_t				phoConvVtxErr[13][3];
 extern Float_t				phoConvPairMomentum[13][3];
 extern Float_t				phoConvRefittedMomentum[13][3];
 extern Int_t				SingleLegConv[13];
 extern Float_t				phoPFConvVtx[13][3];
 extern Float_t				phoPFConvMom[13][3];
 extern Float_t				phoESEffSigmaRR[13][3];
 extern Int_t				muTrg[21][10];
 extern Float_t				muEta[21];
 extern Float_t				muPhi[21];
 extern Int_t				muCharge[21];
 extern Float_t				muPt[21];
 extern Float_t				muPz[21];
 extern Float_t				muVtx[21][3];
 extern Float_t				muVtxGlb[21][3];
 extern Int_t				muGenIndex[21];
 extern Float_t				mucktPt[21];
 extern Float_t				mucktPtErr[21];
 extern Float_t				mucktEta[21];
 extern Float_t				mucktPhi[21];
 extern Float_t				mucktdxy[21];
 extern Float_t				mucktdz[21];
 extern Float_t				muIsoTrk[21];
 extern Float_t				muIsoCalo[21];
 extern Float_t				muIsoEcal[21];
 extern Float_t				muIsoHcal[21];
 extern Float_t				muChi2NDF[21];
 extern Float_t				muInnerChi2NDF[21];
 extern Float_t				muPFIsoR04_CH[21];
 extern Float_t				muPFIsoR04_NH[21];
 extern Float_t				muPFIsoR04_Pho[21];
 extern Float_t				muPFIsoR04_PU[21];
 extern Float_t				muPFIsoR04_CPart[21];
 extern Float_t				muPFIsoR04_NHHT[21];
 extern Float_t				muPFIsoR04_PhoHT[21];
 extern Float_t				muPFIsoR03_CH[21];
 extern Float_t				muPFIsoR03_NH[21];
 extern Float_t				muPFIsoR03_Pho[21];
 extern Float_t				muPFIsoR03_PU[21];
 extern Float_t				muPFIsoR03_CPart[21];
 extern Float_t				muPFIsoR03_NHHT[21];
 extern Float_t				muPFIsoR03_PhoHT[21];
 extern Int_t				muType[21];
 extern Float_t				muD0[21];
 extern Float_t				muDz[21];
 extern Float_t				muD0GV[21];
 extern Float_t				muDzGV[21];
 extern Float_t				muD0Vtx[21][100];
 extern Float_t				muDzVtx[21][100];
 extern Float_t				muInnerD0[21];
 extern Float_t				muInnerDz[21];
 extern Float_t				muInnerD0GV[21];
 extern Float_t				muInnerDzGV[21];
 extern Float_t				muInnerPt[21];
 extern Float_t				muInnerPtErr[21];
 extern Int_t				muNumberOfValidTrkLayers[21];
 extern Int_t				muNumberOfValidTrkHits[21];
 extern Int_t				muNumberOfValidPixelLayers[21];
 extern Int_t				muNumberOfValidPixelHits[21];
 extern Int_t				muNumberOfValidMuonHits[21];
 extern Int_t				muStations[21];
 extern Int_t				muChambers[21];
 extern Float_t				muIP3D[21];
 extern Float_t				muIP3DErr[21];
 extern Float_t				PFPhoEt[54];
 extern Float_t				PFPhoEta[54];
 extern Float_t				PFPhoPhi[54];
 extern Int_t				PFPhoType[54];
 extern Float_t				PFPhoIso[54];
 extern Float_t				rho25;
 extern Float_t				rho25_neu;
 extern Float_t				rho25_muPFiso;
 extern Float_t				rho25_elePFiso;
 extern Float_t				rho2011;
 extern Float_t				rho2012;
 extern Int_t				jetTrg[96][14];
 extern Float_t				jetEn[96];
 extern Float_t				jetPt[96];
 extern Float_t				jetEta[96];
 extern Float_t				jetPhi[96];
 extern Float_t				jetCharge[96];
 extern Float_t				jetEt[96];
 extern Float_t				jetRawPt[96];
 extern Float_t				jetRawEn[96];
 extern Float_t				jetArea[96];
 extern Float_t				jetCHF[96];
 extern Float_t				jetNHF[96];
 extern Float_t				jetCEF[96];
 extern Float_t				jetNEF[96];
 extern Int_t				jetNCH[96];
 extern Float_t				jetHFHAE[96];
 extern Float_t				jetHFEME[96];
 extern Int_t				jetNConstituents[96];
 extern Float_t				jetCombinedSecondaryVtxBJetTags[96];
 extern Float_t				jetCombinedSecondaryVtxMVABJetTags[96];
 extern Float_t				jetJetProbabilityBJetTags[96];
 extern Float_t				jetJetBProbabilityBJetTags[96];
 extern Float_t				jetTrackCountingHighPurBJetTags[96];
 extern Float_t				jetBetaStar[96][100];
 extern Bool_t				jetPFLooseId[96];
 extern Float_t				jetDRMean[96];
 extern Float_t				jetDR2Mean[96];
 extern Float_t				jetDZ[96];
 extern Float_t				jetFrac01[96];
 extern Float_t				jetFrac02[96];
 extern Float_t				jetFrac03[96];
 extern Float_t				jetFrac04[96];
 extern Float_t				jetFrac05[96];
 extern Float_t				jetFrac06[96];
 extern Float_t				jetFrac07[96];
 extern Float_t				jetBeta[96];
 extern Float_t				jetBetaStarCMG[96];
 extern Float_t				jetBetaStarClassic[96];
 extern Float_t				jetBetaExt[96][100];
 extern Float_t				jetBetaStarCMGExt[96][100];
 extern Float_t				jetBetaStarClassicExt[96][100];
 extern Float_t				jetNNeutrals[96];
 extern Float_t				jetNCharged[96];
 extern Float_t				jetMVAs[96][4];
 extern Int_t				jetWPLevels[96][4];
 extern Float_t				jetMVAsExt[96][4][100];
 extern Int_t				jetWPLevelsExt[96][4][100];
 extern Float_t				jetMt[96];
 extern Float_t				jetJECUnc[96];
 extern Float_t				jetLeadTrackPt[96];
 extern Float_t				jetVtxPt[96];
 extern Float_t				jetVtxMass[96];
 extern Float_t				jetVtx3dL[96];
 extern Float_t				jetVtx3deL[96];
 extern Float_t				jetSoftLeptPt[96];
 extern Float_t				jetSoftLeptPtRel[96];
 extern Float_t				jetSoftLeptdR[96];
 extern Float_t				jetSoftLeptIdlooseMu[96];
 extern Float_t				jetSoftLeptIdEle95[96];
 extern Float_t				jetDPhiMETJet[96];
 extern Float_t				jetPuJetIdL[96];
 extern Float_t				jetPuJetIdM[96];
 extern Float_t				jetPuJetIdT[96];
 extern Int_t				jetPartonID[96];
 extern Int_t				jetGenJetIndex[96];
 extern Float_t				jetGenJetEn[96];
 extern Float_t				jetGenJetPt[96];
 extern Float_t				jetGenJetEta[96];
 extern Float_t				jetGenJetPhi[96];
 extern Int_t				jetGenPartonID[96];
 extern Float_t				jetGenEn[96];
 extern Float_t				jetGenPt[96];
 extern Float_t				jetGenEta[96];
 extern Float_t				jetGenPhi[96];
 extern Float_t				jetLowPtEn[64];
 extern Float_t				jetLowPtPt[64];
 extern Float_t				jetLowPtEta[64];
 extern Float_t				jetLowPtPhi[64];
 extern Float_t				jetLowPtCharge[64];
 extern Float_t				jetLowPtEt[64];
 extern Float_t				jetLowPtRawPt[64];
 extern Float_t				jetLowPtRawEn[64];
 extern Float_t				jetLowPtArea[64];
 extern Int_t				jetLowPtPartonID[64];
 extern Float_t				jetLowPtGenJetEn[64];
 extern Float_t				jetLowPtGenJetPt[64];
 extern Float_t				jetLowPtGenJetEta[64];
 extern Float_t				jetLowPtGenJetPhi[64];
 extern Int_t				jetLowPtGenPartonID[64];
 extern Float_t				jetLowPtGenEn[64];
 extern Float_t				jetLowPtGenPt[64];
 extern Float_t				jetLowPtGenEta[64];
 extern Float_t				jetLowPtGenPhi[64];
 extern Float_t				convP4[173][4];
 extern Float_t				convVtx[173][3];
 extern Float_t				convVtxErr[173][3];
 extern Float_t				convPairMomentum[173][3];
 extern Float_t				convRefittedMomentum[173][3];
 extern Int_t				convNTracks[173];
 extern Float_t				convPairInvMass[173];
 extern Float_t				convPairCotThetaSep[173];
 extern Float_t				convEoverP[173];
 extern Float_t				convDistOfMinApproach[173];
 extern Float_t				convDPhiTrksAtVtx[173];
 extern Float_t				convDPhiTrksAtEcal[173];
 extern Float_t				convDEtaTrksAtEcal[173];
 extern Float_t				convDxy[173];
 extern Float_t				convDz[173];
 extern Float_t				convLxy[173];
 extern Float_t				convLz[173];
 extern Float_t				convZofPrimVtxFromTrks[173];
 extern Int_t				convNHitsBeforeVtx[173][2];
 extern Int_t				convNSharedHits[173];
 extern Int_t				convValidVtx[173];
 extern Float_t				convMVALikelihood[173];
 extern Float_t				convChi2[173];
 extern Float_t				convChi2Probability[173];
 extern Float_t				convTk1Dz[173];
 extern Float_t				convTk2Dz[173];
 extern Float_t				convTk1DzErr[173];
 extern Float_t				convTk2DzErr[173];
 extern Int_t				convCh1Ch2[173];
 extern Float_t				convTk1D0[173];
 extern Float_t				convTk1Pout[173];
 extern Float_t				convTk1Pin[173];
 extern Float_t				convTk2D0[173];
 extern Float_t				convTk2Pout[173];
 extern Float_t				convTk2Pin[173];
};
namespace OUT {
 extern Int_t				nConv;
 extern Int_t				nLowPtJet;
 extern Int_t				nJet;
 extern Int_t				nPFPho;
 extern Int_t				nMu;
 extern Int_t				nPho;
 extern Int_t				nEle;
 extern Int_t				nPUInfo;
 extern Int_t				nMC;
 extern Int_t				nVtxBS;
 extern Int_t				nVtx;
 extern Int_t				nHLT;
 extern Int_t				run;
 extern Long64_t				event;
 extern Int_t				lumis;
 extern Bool_t				isData;
 extern Int_t				HLT[444];
 extern Int_t				HLTIndex[70];
 extern Float_t				bspotPos[3];
 extern Float_t				vtx[64][3];
 extern Int_t				IsVtxGood;
 extern Int_t				nGoodVtx;
 extern Float_t				vtxbs[64][3];
 extern Float_t				pdf[7];
 extern Float_t				pthat;
 extern Float_t				processID;
 extern Int_t				mcPID[138];
 extern Float_t				mcVtx[138][3];
 extern Float_t				mcPt[138];
 extern Float_t				mcEta[138];
 extern Float_t				mcPhi[138];
 extern Float_t				mcE[138];
 extern Int_t				mcGMomPID[138];
 extern Int_t				mcMomPID[138];
 extern Float_t				mcMomPt[138];
 extern Float_t				mcMomMass[138];
 extern Float_t				mcMomEta[138];
 extern Float_t				mcMomPhi[138];
 extern Int_t				mcIndex[138];
 extern Int_t				mcDecayType[138];
 extern Int_t				mcParentage[138];
 extern Int_t				mcStatus[138];
 extern Float_t				genMET;
 extern Float_t				genMETPhi;
 extern Int_t				nPU[4];
 extern Int_t				puBX[4];
 extern Float_t				puTrue[4];
 extern Float_t				pfMET;
 extern Float_t				pfMETPhi;
 extern Float_t				pfMETsumEt;
 extern Float_t				pfMETmEtSig;
 extern Float_t				pfMETSig;
 extern Float_t				recoPfMET;
 extern Float_t				recoPfMETPhi;
 extern Float_t				recoPfMETsumEt;
 extern Float_t				recoPfMETmEtSig;
 extern Float_t				recoPfMETSig;
 extern Float_t				trkMETxPV;
 extern Float_t				trkMETyPV;
 extern Float_t				trkMETPhiPV;
 extern Float_t				trkMETPV;
 extern Float_t				trkMETx[64];
 extern Float_t				trkMETy[64];
 extern Float_t				trkMETPhi[64];
 extern Float_t				trkMET[64];
 extern Int_t				metFilters[10];
 extern Int_t				eleTrg[13][16];
 extern Int_t				eleClass[13];
 extern Int_t				eleIsEcalDriven[13];
 extern Int_t				eleCharge[13];
 extern Float_t				eleEn[13];
 extern Float_t				eleEcalEn[13];
 extern Float_t				eleSCRawEn[13];
 extern Float_t				eleSCEn[13];
 extern Float_t				eleESEn[13];
 extern Float_t				elePt[13];
 extern Float_t				eleEta[13];
 extern Float_t				elePhi[13];
 extern Float_t				eleEtaVtx[13][100];
 extern Float_t				elePhiVtx[13][100];
 extern Float_t				eleEtVtx[13][100];
 extern Float_t				eleSCEta[13];
 extern Float_t				eleSCPhi[13];
 extern Float_t				eleSCEtaWidth[13];
 extern Float_t				eleSCPhiWidth[13];
 extern Float_t				eleVtx[13][3];
 extern Float_t				eleD0[13];
 extern Float_t				eleDz[13];
 extern Float_t				eleD0GV[13];
 extern Float_t				eleDzGV[13];
 extern Float_t				eleD0Vtx[13][100];
 extern Float_t				eleDzVtx[13][100];
 extern Float_t				eleHoverE[13];
 extern Float_t				eleHoverE12[13];
 extern Float_t				eleEoverP[13];
 extern Float_t				elePin[13];
 extern Float_t				elePout[13];
 extern Float_t				eleTrkMomErr[13];
 extern Float_t				eleBrem[13];
 extern Float_t				eledEtaAtVtx[13];
 extern Float_t				eledPhiAtVtx[13];
 extern Float_t				eleSigmaIEtaIEta[13];
 extern Float_t				eleSigmaIEtaIPhi[13];
 extern Float_t				eleSigmaIPhiIPhi[13];
 extern Float_t				eleEmax[13];
 extern Float_t				eleE1x5[13];
 extern Float_t				eleE3x3[13];
 extern Float_t				eleE5x5[13];
 extern Float_t				eleE2x5Max[13];
 extern Float_t				eleRegrE[13];
 extern Float_t				eleRegrEerr[13];
 extern Float_t				elePhoRegrE[13];
 extern Float_t				elePhoRegrEerr[13];
 extern Float_t				eleSeedTime[13];
 extern Int_t				eleRecoFlag[13];
 extern Int_t				elePos[13];
 extern Int_t				eleGenIndex[13];
 extern Int_t				eleGenGMomPID[13];
 extern Int_t				eleGenMomPID[13];
 extern Float_t				eleGenMomPt[13];
 extern Float_t				eleIsoTrkDR03[13];
 extern Float_t				eleIsoEcalDR03[13];
 extern Float_t				eleIsoHcalDR03[13];
 extern Float_t				eleIsoHcalDR0312[13];
 extern Float_t				eleIsoTrkDR04[13];
 extern Float_t				eleIsoEcalDR04[13];
 extern Float_t				eleIsoHcalDR04[13];
 extern Float_t				eleIsoHcalDR0412[13];
 extern Float_t				eleModIsoTrk[13];
 extern Float_t				eleModIsoEcal[13];
 extern Float_t				eleModIsoHcal[13];
 extern Int_t				eleMissHits[13];
 extern Float_t				eleConvDist[13];
 extern Float_t				eleConvDcot[13];
 extern Int_t				eleConvVtxFit[13];
 extern Float_t				eleIP3D[13];
 extern Float_t				eleIP3DErr[13];
 extern Float_t				eleIDMVANonTrig[13];
 extern Float_t				eleIDMVATrig[13];
 extern Float_t				eleIDMVATrigIDIso[13];
 extern Float_t				elePFChIso03[13];
 extern Float_t				elePFPhoIso03[13];
 extern Float_t				elePFNeuIso03[13];
 extern Float_t				elePFChIso04[13];
 extern Float_t				elePFPhoIso04[13];
 extern Float_t				elePFNeuIso04[13];
 extern Float_t				eleESEffSigmaRR[13][3];
 extern Int_t				phoTrg[13][8];
 extern Int_t				phoTrgFilter[13][50];
 extern Bool_t				phoIsPhoton[13];
 extern Float_t				phoSCPos[13][3];
 extern Float_t				phoCaloPos[13][3];
 extern Float_t				phoE[13];
 extern Float_t				phoEt[13];
 extern Float_t				phoEta[13];
 extern Float_t				phoVtx[13][3];
 extern Float_t				phoPhi[13];
 extern Float_t				phoR9[13];
 extern Float_t				phoTrkIsoHollowDR03[13];
 extern Float_t				phoEcalIsoDR03[13];
 extern Float_t				phoHcalIsoDR03[13];
 extern Float_t				phoHcalIsoDR0312[13];
 extern Float_t				phoTrkIsoHollowDR04[13];
 extern Float_t				phoCiCTrkIsoDR03[13][100];
 extern Float_t				phoCiCTrkIsoDR04[13][100];
 extern Float_t				phoCiCdRtoTrk[13];
 extern Float_t				phoEcalIsoDR04[13];
 extern Float_t				phoHcalIsoDR04[13];
 extern Float_t				phoHcalIsoDR0412[13];
 extern Float_t				phoHoverE[13];
 extern Float_t				phoHoverE12[13];
 extern Int_t				phoEleVeto[13];
 extern Float_t				phoSigmaIEtaIEta[13];
 extern Float_t				phoSigmaIEtaIPhi[13];
 extern Float_t				phoSigmaIPhiIPhi[13];
 extern Float_t				phoCiCPF4phopfIso03[13];
 extern Float_t				phoCiCPF4phopfIso04[13];
 extern Float_t				phoCiCPF4chgpfIso02[13][100];
 extern Float_t				phoCiCPF4chgpfIso03[13][100];
 extern Float_t				phoCiCPF4chgpfIso04[13][100];
 extern Float_t				phoEmax[13];
 extern Float_t				phoE3x3[13];
 extern Float_t				phoE3x1[13];
 extern Float_t				phoE1x3[13];
 extern Float_t				phoE5x5[13];
 extern Float_t				phoE1x5[13];
 extern Float_t				phoE2x2[13];
 extern Float_t				phoE2x5Max[13];
 extern Float_t				phoPFChIso[13];
 extern Float_t				phoPFPhoIso[13];
 extern Float_t				phoPFNeuIso[13];
 extern Float_t				phoSCRChIso[13];
 extern Float_t				phoSCRPhoIso[13];
 extern Float_t				phoSCRNeuIso[13];
 extern Float_t				phoRegrE[13];
 extern Float_t				phoRegrEerr[13];
 extern Float_t				phoSeedTime[13];
 extern Int_t				phoSeedDetId1[13];
 extern Int_t				phoSeedDetId2[13];
 extern Float_t				phoLICTD[13];
 extern Int_t				phoRecoFlag[13];
 extern Int_t				phoPos[13];
 extern Int_t				phoGenIndex[13];
 extern Int_t				phoGenGMomPID[13];
 extern Int_t				phoGenMomPID[13];
 extern Float_t				phoGenMomPt[13];
 extern Float_t				phoSCE[13];
 extern Float_t				phoSCRawE[13];
 extern Float_t				phoESEn[13];
 extern Float_t				phoSCEt[13];
 extern Float_t				phoSCEta[13];
 extern Float_t				phoSCPhi[13];
 extern Float_t				phoSCEtaWidth[13];
 extern Float_t				phoSCPhiWidth[13];
 extern Float_t				phoSCBrem[13];
 extern Int_t				phoOverlap[13];
 extern Int_t				phohasPixelSeed[13];
 extern Int_t				pho_hasConvPf[13];
 extern Int_t				pho_hasSLConvPf[13];
 extern Float_t				pho_pfconvVtxZ[13];
 extern Float_t				pho_pfconvVtxZErr[13];
 extern Int_t				pho_nSLConv[13];
 extern Float_t				pho_pfSLConvPos[13][20][3];
 extern Float_t				pho_pfSLConvVtxZ[13][20];
 extern Int_t				phoIsConv[13];
 extern Int_t				phoNConv[13];
 extern Float_t				phoConvInvMass[13];
 extern Float_t				phoConvCotTheta[13];
 extern Float_t				phoConvEoverP[13];
 extern Float_t				phoConvZofPVfromTrks[13];
 extern Float_t				phoConvMinDist[13];
 extern Float_t				phoConvdPhiAtVtx[13];
 extern Float_t				phoConvdPhiAtCalo[13];
 extern Float_t				phoConvdEtaAtCalo[13];
 extern Float_t				phoConvTrkd0[13][2];
 extern Float_t				phoConvTrkPin[13][2];
 extern Float_t				phoConvTrkPout[13][2];
 extern Float_t				phoConvTrkdz[13][2];
 extern Float_t				phoConvTrkdzErr[13][2];
 extern Float_t				phoConvChi2[13];
 extern Float_t				phoConvChi2Prob[13];
 extern Int_t				phoConvNTrks[13];
 extern Float_t				phoConvCharge[13][2];
 extern Float_t				phoConvValidVtx[13];
 extern Float_t				phoConvLikeLihood[13];
 extern Float_t				phoConvP4[13][4];
 extern Float_t				phoConvVtx[13][3];
 extern Float_t				phoConvVtxErr[13][3];
 extern Float_t				phoConvPairMomentum[13][3];
 extern Float_t				phoConvRefittedMomentum[13][3];
 extern Int_t				SingleLegConv[13];
 extern Float_t				phoPFConvVtx[13][3];
 extern Float_t				phoPFConvMom[13][3];
 extern Float_t				phoESEffSigmaRR[13][3];
 extern Int_t				muTrg[21][10];
 extern Float_t				muEta[21];
 extern Float_t				muPhi[21];
 extern Int_t				muCharge[21];
 extern Float_t				muPt[21];
 extern Float_t				muPz[21];
 extern Float_t				muVtx[21][3];
 extern Float_t				muVtxGlb[21][3];
 extern Int_t				muGenIndex[21];
 extern Float_t				mucktPt[21];
 extern Float_t				mucktPtErr[21];
 extern Float_t				mucktEta[21];
 extern Float_t				mucktPhi[21];
 extern Float_t				mucktdxy[21];
 extern Float_t				mucktdz[21];
 extern Float_t				muIsoTrk[21];
 extern Float_t				muIsoCalo[21];
 extern Float_t				muIsoEcal[21];
 extern Float_t				muIsoHcal[21];
 extern Float_t				muChi2NDF[21];
 extern Float_t				muInnerChi2NDF[21];
 extern Float_t				muPFIsoR04_CH[21];
 extern Float_t				muPFIsoR04_NH[21];
 extern Float_t				muPFIsoR04_Pho[21];
 extern Float_t				muPFIsoR04_PU[21];
 extern Float_t				muPFIsoR04_CPart[21];
 extern Float_t				muPFIsoR04_NHHT[21];
 extern Float_t				muPFIsoR04_PhoHT[21];
 extern Float_t				muPFIsoR03_CH[21];
 extern Float_t				muPFIsoR03_NH[21];
 extern Float_t				muPFIsoR03_Pho[21];
 extern Float_t				muPFIsoR03_PU[21];
 extern Float_t				muPFIsoR03_CPart[21];
 extern Float_t				muPFIsoR03_NHHT[21];
 extern Float_t				muPFIsoR03_PhoHT[21];
 extern Int_t				muType[21];
 extern Float_t				muD0[21];
 extern Float_t				muDz[21];
 extern Float_t				muD0GV[21];
 extern Float_t				muDzGV[21];
 extern Float_t				muD0Vtx[21][100];
 extern Float_t				muDzVtx[21][100];
 extern Float_t				muInnerD0[21];
 extern Float_t				muInnerDz[21];
 extern Float_t				muInnerD0GV[21];
 extern Float_t				muInnerDzGV[21];
 extern Float_t				muInnerPt[21];
 extern Float_t				muInnerPtErr[21];
 extern Int_t				muNumberOfValidTrkLayers[21];
 extern Int_t				muNumberOfValidTrkHits[21];
 extern Int_t				muNumberOfValidPixelLayers[21];
 extern Int_t				muNumberOfValidPixelHits[21];
 extern Int_t				muNumberOfValidMuonHits[21];
 extern Int_t				muStations[21];
 extern Int_t				muChambers[21];
 extern Float_t				muIP3D[21];
 extern Float_t				muIP3DErr[21];
 extern Float_t				PFPhoEt[54];
 extern Float_t				PFPhoEta[54];
 extern Float_t				PFPhoPhi[54];
 extern Int_t				PFPhoType[54];
 extern Float_t				PFPhoIso[54];
 extern Float_t				rho25;
 extern Float_t				rho25_neu;
 extern Float_t				rho25_muPFiso;
 extern Float_t				rho25_elePFiso;
 extern Float_t				rho2011;
 extern Float_t				rho2012;
 extern Int_t				jetTrg[96][14];
 extern Float_t				jetEn[96];
 extern Float_t				jetPt[96];
 extern Float_t				jetEta[96];
 extern Float_t				jetPhi[96];
 extern Float_t				jetCharge[96];
 extern Float_t				jetEt[96];
 extern Float_t				jetRawPt[96];
 extern Float_t				jetRawEn[96];
 extern Float_t				jetArea[96];
 extern Float_t				jetCHF[96];
 extern Float_t				jetNHF[96];
 extern Float_t				jetCEF[96];
 extern Float_t				jetNEF[96];
 extern Int_t				jetNCH[96];
 extern Float_t				jetHFHAE[96];
 extern Float_t				jetHFEME[96];
 extern Int_t				jetNConstituents[96];
 extern Float_t				jetCombinedSecondaryVtxBJetTags[96];
 extern Float_t				jetCombinedSecondaryVtxMVABJetTags[96];
 extern Float_t				jetJetProbabilityBJetTags[96];
 extern Float_t				jetJetBProbabilityBJetTags[96];
 extern Float_t				jetTrackCountingHighPurBJetTags[96];
 extern Float_t				jetBetaStar[96][100];
 extern Bool_t				jetPFLooseId[96];
 extern Float_t				jetDRMean[96];
 extern Float_t				jetDR2Mean[96];
 extern Float_t				jetDZ[96];
 extern Float_t				jetFrac01[96];
 extern Float_t				jetFrac02[96];
 extern Float_t				jetFrac03[96];
 extern Float_t				jetFrac04[96];
 extern Float_t				jetFrac05[96];
 extern Float_t				jetFrac06[96];
 extern Float_t				jetFrac07[96];
 extern Float_t				jetBeta[96];
 extern Float_t				jetBetaStarCMG[96];
 extern Float_t				jetBetaStarClassic[96];
 extern Float_t				jetBetaExt[96][100];
 extern Float_t				jetNNeutrals[96];
 extern Float_t				jetNCharged[96];
 extern Float_t				jetMVAs[96][4];
 extern Int_t				jetWPLevels[96][4];
 extern Float_t				jetMt[96];
 extern Float_t				jetJECUnc[96];
 extern Float_t				jetLeadTrackPt[96];
 extern Float_t				jetVtxPt[96];
 extern Float_t				jetVtxMass[96];
 extern Float_t				jetVtx3dL[96];
 extern Float_t				jetVtx3deL[96];
 extern Float_t				jetSoftLeptPt[96];
 extern Float_t				jetSoftLeptPtRel[96];
 extern Float_t				jetSoftLeptdR[96];
 extern Float_t				jetSoftLeptIdlooseMu[96];
 extern Float_t				jetSoftLeptIdEle95[96];
 extern Float_t				jetDPhiMETJet[96];
 extern Float_t				jetPuJetIdL[96];
 extern Float_t				jetPuJetIdM[96];
 extern Float_t				jetPuJetIdT[96];
 extern Int_t				jetPartonID[96];
 extern Int_t				jetGenJetIndex[96];
 extern Float_t				jetGenJetEn[96];
 extern Float_t				jetGenJetPt[96];
 extern Float_t				jetGenJetEta[96];
 extern Float_t				jetGenJetPhi[96];
 extern Int_t				jetGenPartonID[96];
 extern Float_t				jetGenEn[96];
 extern Float_t				jetGenPt[96];
 extern Float_t				jetGenEta[96];
 extern Float_t				jetGenPhi[96];
 extern Float_t				convVtx[173][3];
 extern Float_t				convVtxErr[173][3];
 extern Float_t				convPairMomentum[173][3];
 extern Float_t				convRefittedMomentum[173][3];
 extern Int_t				convNTracks[173];
 extern Float_t				convPairInvMass[173];
 extern Float_t				convPairCotThetaSep[173];
 extern Float_t				convEoverP[173];
 extern Float_t				convDistOfMinApproach[173];
 extern Float_t				convDPhiTrksAtVtx[173];
 extern Float_t				convDPhiTrksAtEcal[173];
 extern Float_t				convDEtaTrksAtEcal[173];
 extern Float_t				convDxy[173];
 extern Float_t				convDz[173];
 extern Float_t				convLxy[173];
 extern Float_t				convLz[173];
 extern Float_t				convZofPrimVtxFromTrks[173];
 extern Int_t				convNHitsBeforeVtx[173][2];
 extern Int_t				convNSharedHits[173];
 extern Int_t				convValidVtx[173];
 extern Float_t				convMVALikelihood[173];
 extern Float_t				convChi2[173];
 extern Float_t				convChi2Probability[173];
 extern Float_t				convTk1Dz[173];
 extern Float_t				convTk2Dz[173];
 extern Float_t				convTk1DzErr[173];
 extern Float_t				convTk2DzErr[173];
 extern Int_t				convCh1Ch2[173];
 extern Float_t				convTk1D0[173];
 extern Float_t				convTk1Pout[173];
 extern Float_t				convTk1Pin[173];
 extern Float_t				convTk2D0[173];
 extern Float_t				convTk2Pout[173];
 extern Float_t				convTk2Pin[173];
};
#endif
