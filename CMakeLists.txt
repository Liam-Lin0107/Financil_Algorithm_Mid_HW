cmake_minimum_required(VERSION 3.21)
project(OptionCalculator)

set(CMAKE_CXX_STANDARD 20)

add_executable(OptionCalculator main.cpp
        src/BinomialTree/CRRBinomialTree.cpp
        src/BinomialTree/CRRBinomialTree.h
        src/CombinatorialMehtod/CombinatorialMethod.cpp
        src/CombinatorialMehtod/CombinatorialMethod.h
        src/ImpliedVolatility/src/ImpliiedVolatility.cpp
        src/ImpliedVolatility/src/ImpliiedVolatility.h
        src/ImpliedVolatility/util/BSModel.cpp
        src/ImpliedVolatility/util/BSModel.h
        src/ImpliedVolatility/util/NormalCDF.cpp
        src/ImpliedVolatility/util/NormalCDF.h
        src/MonteCarlo/Simulation/Simulator/PathIndependentSimulation/SimpleMCSimulation.h
        src/MonteCarlo/Simulation/Simulator/PathIndependentSimulation/SimpleMCSimulation.cpp
        src/MonteCarlo/Simulation/Simulator/PathdependentSimulation/DependentSimulator.cpp
        src/MonteCarlo/Statics/RandomSample.cpp
        src/MonteCarlo/Simulation/Simulator/PathIndependentSimulation/Simulator.h
        src/MonteCarlo/Statics/SummaryStatistics.cpp
        src/MonteCarlo/Simulation/Simulator/PathdependentSimulation/DependentSimpleMCSimulation.h
        src/MonteCarlo/Simulation/Simulator/PathdependentSimulation/DependentSimulator.h
        src/MonteCarlo/Simulation/Simulator/PathdependentSimulation/DependentSimpleMCSimulation.cpp
        src/MonteCarlo/Statics/SummaryStatistics.h
        src/MonteCarlo/Simulation/Simulator/PathIndependentSimulation/Simulator.cpp
        src/MonteCarlo/Statics/RandomSample.h
        src/MonteCarlo/PayOff/Payoff.h
        src/MonteCarlo/PayOff/Payoff.cpp
        src/MonteCarlo/PayOff/HW1_Option.h
        src/MonteCarlo/PayOff/HW1_Option.cpp
        src/MonteCarlo/PayOff/EuropeanPut.h
        src/MonteCarlo/PayOff/EuropeanPut.cpp
        src/MonteCarlo/PayOff/EuropeanCall.h
        src/MonteCarlo/PayOff/EuropeanCall.cpp
        src/MonteCarlo/Discount/Discount.h
        src/CombinatorialMehtod/util/BinomialPF.cpp
        src/CombinatorialMehtod/util/BinomialPF.h)
