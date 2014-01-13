/**********************************************************************
 *  Copyright (c) 2008-2014, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#ifndef MODEL_GASMIXTURE_IMPL_HPP
#define MODEL_GASMIXTURE_IMPL_HPP

#include <model/ModelAPI.hpp>
#include <model/GasLayer_Impl.hpp>

#include <utilities/units/Quantity.hpp>
#include <utilities/units/OSOptionalQuantity.hpp>

namespace openstudio {
namespace model {

namespace detail {

  /** GasMixture_Impl is a GasLayer_Impl that is the implementation class for GasMixture.*/
  class MODEL_API GasMixture_Impl : public GasLayer_Impl {
    Q_OBJECT;

    Q_PROPERTY(double thickness READ thickness WRITE setThickness);
    Q_PROPERTY(openstudio::Quantity thickness_SI READ thickness_SI WRITE setThickness);
    Q_PROPERTY(openstudio::Quantity thickness_IP READ thickness_IP WRITE setThickness);

    Q_PROPERTY(int numberofGasesinMixture READ numberofGasesinMixture WRITE setNumberofGasesinMixture);

    Q_PROPERTY(std::string gas1Type READ gas1Type WRITE setGas1Type);
    Q_PROPERTY(std::vector<std::string> gas1TypeValues READ gas1TypeValues);

    Q_PROPERTY(double gas1Fraction READ gas1Fraction WRITE setGas1Fraction);
    Q_PROPERTY(openstudio::Quantity gas1Fraction_SI READ gas1Fraction_SI WRITE setGas1Fraction);
    Q_PROPERTY(openstudio::Quantity gas1Fraction_IP READ gas1Fraction_IP WRITE setGas1Fraction);

    Q_PROPERTY(std::string gas2Type READ gas2Type WRITE setGas2Type);
    Q_PROPERTY(std::vector<std::string> gas2TypeValues READ gas2TypeValues);

    Q_PROPERTY(double gas2Fraction READ gas2Fraction WRITE setGas2Fraction);
    Q_PROPERTY(openstudio::Quantity gas2Fraction_SI READ gas2Fraction_SI WRITE setGas2Fraction);
    Q_PROPERTY(openstudio::Quantity gas2Fraction_IP READ gas2Fraction_IP WRITE setGas2Fraction);

    Q_PROPERTY(std::string gas3Type READ gas3Type WRITE setGas3Type RESET resetGas3Type);
    Q_PROPERTY(std::vector<std::string> gas3TypeValues READ gas3TypeValues);

    Q_PROPERTY(boost::optional<double> gas3Fraction READ gas3Fraction WRITE setGas3Fraction RESET resetGas3Fraction);
    Q_PROPERTY(openstudio::OSOptionalQuantity gas3Fraction_SI READ gas3Fraction_SI WRITE setGas3Fraction RESET resetGas3Fraction);
    Q_PROPERTY(openstudio::OSOptionalQuantity gas3Fraction_IP READ gas3Fraction_IP WRITE setGas3Fraction RESET resetGas3Fraction);

    Q_PROPERTY(std::string gas4Type READ gas4Type WRITE setGas4Type RESET resetGas4Type);
    Q_PROPERTY(std::vector<std::string> gas4TypeValues READ gas4TypeValues);

    Q_PROPERTY(boost::optional<double> gas4Fraction READ gas4Fraction WRITE setGas4Fraction RESET resetGas4Fraction);
    Q_PROPERTY(openstudio::OSOptionalQuantity gas4Fraction_SI READ gas4Fraction_SI WRITE setGas4Fraction RESET resetGas4Fraction);
    Q_PROPERTY(openstudio::OSOptionalQuantity gas4Fraction_IP READ gas4Fraction_IP WRITE setGas4Fraction RESET resetGas4Fraction);

    // TODO: Add relationships for objects related to this one, but not pointed to by the underlying data.
    //       Such relationships can be generated by the GenerateRelationships.rb script.
   public:
    /** @name Constructors and Destructors */
    //@{

    GasMixture_Impl(const IdfObject& idfObject,
                    Model_Impl* model,
                    bool keepHandle);

    GasMixture_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                    Model_Impl* model,
                    bool keepHandle);

    GasMixture_Impl(const GasMixture_Impl& other,
                    Model_Impl* model,
                    bool keepHandle);

    virtual ~GasMixture_Impl() {}

    //@}

    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;

    //@}
    /** @name Getters */
    //@{

    /** Get the thickness of the material. */
    virtual double thickness() const;

    /** Get the type of gas at index, where index starts at 0. Throws if unavailable. */
    std::string getGasType(unsigned index) const;

    double getGasFraction(unsigned index) const;

    /** The conductivity (W/m*K) at temperature (K). Will throw if necessary values are not 
     *  available. */
    double getThermalConductivity(double temperature) const;

    /** The conductance (W/m^2*K) at temperature (K). Will throw if necessary values are not 
     *  available. */
    double getThermalConductance(double temperature) const;

    /** The resistivity (m*K/W) at temperature (K). Will throw if necessary values are not 
     *  available. */
    double getThermalResistivity(double temperature) const;

    /** The resistance (m^2*K/W) at temperature (K). Will throw if necessary values are not 
     *  available. */
    double getThermalResistance(double temperature) const;

    double getViscosity(double temperature) const;

    double getSpecificHeat(double temperature) const;

    Quantity getThickness(bool returnIP=false) const;

    int numberofGasesinMixture() const;

    std::string gas1Type() const;

    double gas1Fraction() const;

    Quantity getGas1Fraction(bool returnIP=false) const;

    std::string gas2Type() const;

    double gas2Fraction() const;

    Quantity getGas2Fraction(bool returnIP=false) const;

    std::string gas3Type() const;

    boost::optional<double> gas3Fraction() const;

    OSOptionalQuantity getGas3Fraction(bool returnIP=false) const;

    std::string gas4Type() const;

    boost::optional<double> gas4Fraction() const;

    OSOptionalQuantity getGas4Fraction(bool returnIP=false) const;

    //@}
    /** @name Setters */
    //@{

    /** Set thickness to value (m). */
    virtual bool setThickness(double value);

    /** Set the gas at index, if index <= numGases. */
    bool setGas(unsigned index, const std::string& type, double fraction);

    bool setGasType(unsigned index, const std::string& type);

    bool setGasFraction(unsigned index, double fraction);

    /** Append gas if numGases < 4. */
    bool addGas(const std::string& type, double fraction);

    /** Set the gas fractions. Length of vector should be equal to numGases, and sum should be
     *  openstudio::equal(1.0). If all fractions except the last is < 1.0, will set last fraction
     *  value if necessary (and issue warning). */
    bool setFractions(const std::vector<double>& fractions);

    /** Assign gas fraction at index to 1.0 - sum(other gas fractions), if index < numGases. */
    bool balanceFractions(unsigned index);

    bool setThickness(const Quantity& thickness);

    bool setNumberofGasesinMixture(int numberofGasesinMixture);

    bool setGas1Type(std::string gas1Type);

    void resetGas1Type();
    
    bool setGas1Fraction(double gas1Fraction);

    bool setGas1Fraction(const Quantity& gas1Fraction);

    void resetGas1Fraction();

    bool setGas2Type(std::string gas2Type);

    void resetGas2Type();

    bool setGas2Fraction(double gas2Fraction);

    bool setGas2Fraction(const Quantity& gas2Fraction);

    void resetGas2Fraction();

    bool setGas3Type(boost::optional<std::string> gas3Type);

    void resetGas3Type();

    bool setGas3Fraction(boost::optional<double> gas3Fraction);

    bool setGas3Fraction(const OSOptionalQuantity& gas3Fraction);

    void resetGas3Fraction();

    bool setGas4Type(boost::optional<std::string> gas4Type);

    void resetGas4Type();

    bool setGas4Fraction(boost::optional<double> gas4Fraction);

    bool setGas4Fraction(const OSOptionalQuantity& gas4Fraction);

    void resetGas4Fraction();

    //@}
    /** @name Queries */
    //@{

    unsigned numGases() const;

    /** Returns a ValidityReport for this Gas object containing all errors at or below level. 
     *  Adds on to the WorkspaceObject requirements by ensuring that custom values are specified
     *  if needed at StrictnessLevel::Final. */
    virtual ValidityReport validityReport(StrictnessLevel level,bool checkNames) const;

    //@}
    /** @name Other */
    //@{

    //@}
   protected:

    virtual void populateValidityReport(ValidityReport& report,bool checkNames) const;

   private:
    REGISTER_LOGGER("openstudio.model.GasMixture");

    unsigned mf_getGasTypeFieldIndex(unsigned gasIndex) const;

    unsigned mf_getGasFractionFieldIndex(unsigned gasIndex) const;

    openstudio::Quantity thickness_SI() const;
    openstudio::Quantity thickness_IP() const;
    std::vector<std::string> gas1TypeValues() const;
    openstudio::Quantity gas1Fraction_SI() const;
    openstudio::Quantity gas1Fraction_IP() const;
    std::vector<std::string> gas2TypeValues() const;
    openstudio::Quantity gas2Fraction_SI() const;
    openstudio::Quantity gas2Fraction_IP() const;
    std::vector<std::string> gas3TypeValues() const;
    openstudio::OSOptionalQuantity gas3Fraction_SI() const;
    openstudio::OSOptionalQuantity gas3Fraction_IP() const;
    std::vector<std::string> gas4TypeValues() const;
    openstudio::OSOptionalQuantity gas4Fraction_SI() const;
    openstudio::OSOptionalQuantity gas4Fraction_IP() const;
  };

} // detail

} // model
} // openstudio

#endif // MODEL_GASMIXTURE_IMPL_HPP

