import sys
from math import pi
from numpy import array, sum, cross
from numpy.linalg import norm

filename = sys.argv[1]
with open(filename,"r") as infile:
    lines = infile.readlines()
masses = array([float(word) for word in lines[0].split()[1:]])
initials = lines[1].split()
finals = lines[-2].split()

initial_values = []
final_values = []
for i in range(1,7):
    initial_values.append([float(word) for word in initials[i::6]])
    final_values.append([float(word) for word in finals[i::6]])
initial_positions = array(initial_values[0:3]).transpose()
initial_velocities = array(initial_values[3:6]).transpose()

final_positions = array(final_values[0:3]).transpose()
final_velocities = array(final_values[3:6]).transpose()


#                                       _
#  _ __ ___   ___  _ __ ___   ___ _ __ | |_ _   _ _ __ ___
# | '_ ` _ \ / _ \| '_ ` _ \ / _ \ '_ \| __| | | | '_ ` _ \
# | | | | | | (_) | | | | | |  __/ | | | |_| |_| | | | | | |
# |_| |_| |_|\___/|_| |_| |_|\___|_| |_|\__|\__,_|_| |_| |_|

initial_momentums = array([mass*velocity for mass,velocity in zip(masses,initial_velocities)])
initial_momentum = sum(initial_momentums,axis=1)
final_momentums = array([mass*velocity for mass,velocity in zip(masses,final_velocities)])
final_momentum = sum(final_momentums,axis=1)

momentum_difference = norm(initial_momentum-final_momentum)
if momentum_difference > 1E-6:
    print "Momentum not conserved!\nInitial: %s\nFinal: %s" % (initial_momentum,final_momentum)
else:
    print "Momentum conserved!"



#   ___ _ __   ___ _ __ __ _ _   _
#  / _ \ '_ \ / _ \ '__/ _` | | | |
# |  __/ | | |  __/ | | (_| | |_| |
#  \___|_| |_|\___|_|  \__, |\__, |
#                      |___/ |___/

initial_kinetic_energy = sum([0.5*m*norm(v)**2 for m, v in zip(masses,initial_velocities)])
final_kinetic_energy = sum([0.5*m*norm(v)**2 for m, v in zip(masses,initial_velocities)])

initial_potential_energy = 0
for i in range(len(masses)-1):
    for j in range(i+1,len(masses)):
        initial_potential_energy -= 4*pi**2*masses[i]*masses[j]/norm(initial_positions[i] - initial_positions[j])

final_potential_energy = 0
for i in range(len(masses)-1):
    for j in range(i+1,len(masses)):
        final_potential_energy -= 4*pi**2*masses[i]*masses[j]/norm(final_positions[i] - final_positions[j])

initial_total_energy = initial_kinetic_energy + initial_potential_energy
final_total_energy = final_kinetic_energy + final_potential_energy
total_energy_difference = abs(initial_total_energy - final_total_energy)
if total_energy_difference > 1E-8:
    print "Total energy not conserved!\nInitial: %s\nFinal: %s" % (initial_total_energy,final_total_energy)
else:
    print "Total energy conserved!"


#                          _
#   __ _ _ __   __ _ _   _| | __ _ _ __
#  / _` | '_ \ / _` | | | | |/ _` | '__|
# | (_| | | | | (_| | |_| | | (_| | |
#  \__,_|_| |_|\__, |\__,_|_|\__,_|_|
#              |___/                    _
#  _ __ ___   ___  _ __ ___   ___ _ __ | |_ _   _ _ __ ___
# | '_ ` _ \ / _ \| '_ ` _ \ / _ \ '_ \| __| | | | '_ ` _ \
# | | | | | | (_) | | | | | |  __/ | | | |_| |_| | | | | | |
# |_| |_| |_|\___/|_| |_| |_|\___|_| |_|\__|\__,_|_| |_| |_|

initial_angular_momentums = array([cross(position,momentum) for position,momentum in zip(initial_positions,initial_momentums)])
initial_angular_momentum = sum(initial_angular_momentums,axis=1)

final_angular_momentums = array([cross(position,momentum) for position,momentum in zip(final_positions,final_momentums)])
final_angular_momentum = sum(final_angular_momentums,axis=1)

angular_momentum_difference = norm(initial_angular_momentum-final_angular_momentum)
if angular_momentum_difference > 1E-8:
    print "Angular momentum not conserved!\nInitial: %s\nFinal: %s" % (initial_angular_momentum,final_angular_momentum)
else:
    print "Angular momentum conserved!"
