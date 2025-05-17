#ifndef SIUNITS_H
#define SIUNITS_H

#ifdef EXPRESS
  TYPE si_prefix = ENUMERATION OF
    (exa,
     peta,
     tera,
     giga,
     mega,
     kilo,
     hecto,
     deca,
     deci,
     centi,
     milli,
     micro,
     nano,
     pico,
     femto,
     atto);
  END_TYPE; -- si_prefix

  TYPE si_unit_name = ENUMERATION OF
    (metre,
     gram,
     second,
     ampere,
     kelvin,
     mole,
     candela,
     radian,
     steradian,
     hertz,
     newton,
     pascal,
     joule,
     watt,
     coulomb,
     volt,
     farad,
     ohm,
     siemens,
     weber,
     tesla,
     henry,
     degree_celsius,
     lumen,
     lux,
     becquerel,
     gray,
     sievert);
  END_TYPE; -- si_unit_name
#endif
#endif
