#
# $Id: /vobs/ecad8/source/pkgs/pcb_base/data/cct_routing_template.do /main/1 1998/08/13 15:06:15 swdev Rel $
#
#  This is a CCT Router dofile template.
#
#  To comment out router commands use a '#' sign in front
#  of the router command.

##################################################################
#                                                                #
#  Sets user units for the design.                               #
#                                                                #
##################################################################

unit inch

##################################################################
#                                                                #
#  Sets up the both the routing grid and via grid.               #
#                                                                #
##################################################################

grid wire 0.005
grid via 0.005

##################################################################
#                                                                #
#  If your design has testpoints already defined and any         #
#  pre-routed traces, this will protect them during routing.     #
#                                                                #
##################################################################

protect all vias
protect all wires

##################################################################
#                                                                #
#  This defines the the first turn of the trace after leaving    #
#  the pad                                                       #
#                                                                #
##################################################################

rule pcb (clearance .1 (type smd_to_turn_gap))
rule pcb (clearance .1 (type pad_to_turn_gap))

##################################################################
#                                                                #
#  The fence command is used for one or more routing keep-ins or #
#  to separate logic functions.                                  #
#                                                                #
#  To use the fencing option you need to know the x, y           #
#  coordinates of the area that you want to fence.               #
#                                                                #
##################################################################

#fence -0.625 -0.455 8.3025 6.9475

##################################################################
#                                                                #
#  The seed command breaks a signal diagonal connection into two #
#  shorter connections by adding a via.                          #
#                                                                #
##################################################################

seedvia 

##################################################################
#                                                                #
#  The sort command controls how connections are scheduled for   #
#  auto-routing. The down option sorts from long to short.       #
#                                                                #
##################################################################

sort length down
fanout 5 (direction in_out)(pin_share on)(via_share on)(share_len 2.0)(pintype all)
bus diagonal
route 25
clean 3
route 50 16
clean 3
route 50 16

##################################################################
#                                                                #
#  The tax command applies a factor to adjust the autorouter     #
#  costs.                                                        #
#                                                                #
##################################################################

tax off_center 100
tax side_exit 100
tax off_grid 100

##################################################################
#                                                                #
#  If the cross or squeeze is less than 1.0 the router creates   #
#  more conflicts but fewer un-connects.                         #
#                                                                #
##################################################################

tax cross .9
tax squeeze .9
clean 3

##################################################################
#                                                                #
#  The spread and center  command attempts to add space between  #
#  wires, and between wires and pins.                            #
#                                                                #
##################################################################

spread
center

##################################################################
#                                                                #
#  The critic command helps improve manufacturability without    #
#  performing a rip-up and re-route operation.                   #
#                                                                #
##################################################################

critic

##################################################################
#                                                                #
#  The filter command tries to remove final routing conflicts.   #
#                                                                #
################################################################## 

filter 5
miter (pin 2.0)(slant 2.0)(bend 2.0 2.0)(tjunction 2.0)(style diagonal)
miter (pin 1.25)(slant 1.25)(bend 1.25 1.25)(tjunction 1.25)(style diagonal)
miter (pin 0.9)(slant 0.9)(bend 0.9 0.9)(tjunction 0.9)(style diagonal)
miter (pin 0.7)(slant 0.7)(bend 0.7 0.7)(tjunction 0.7)(style diagonal)
miter (pin 0.5)(slant 0.5)(bend 0.5 0.5)(tjunction 0.5)(style diagonal)
miter (pin 0.3)(slant 0.3)(bend 0.3 0.3)(tjunction 0.3)(style diagonal)
miter (pin 0.1)(slant 0.1)(bend 0.1 0.1)(tjunction 0.1)(style diagonal)
miter (pin 0.075)(slant 0.075)(bend 0.075 0.075)(tjunction 0.075)(style diagonal)
miter (pin 0.050)(slant 0.05)(bend 0.05 0.05)(tjunction 0.05)(style diagonal)
miter (pin 0.025)(slant 0.025)(bend 0.025 0.025)(tjunction 0.025)(style diagonal)
miter (pin 0.0125)(slant 0.0125)(bend 0.0125 0.0125)(tjunction 0.0125)(style diagonal)

##################################################################
#                                                                #
#  This command turns off routing to all the layers.             #
#                                                                #
##################################################################

unselect layer *

##################################################################
#                                                                #
#  This command turns on routing to just the top and bottom      #
#  layers to run the final passes.                               # 
#                                                                #
#  These final passes should create less cleanup of the top and  #
#  bottom layers.                                                #
#                                                                #
##################################################################

select layer signal_1 signal_2
clean 5
miter (pin 2.0)(slant 2.0)(bend 2.0 2.0)(tjunction 2.0)(style diagonal)
miter (pin 1.25)(slant 1.25)(bend 1.25 1.25)(tjunction 1.25)(style diagonal)
miter (pin 0.9)(slant 0.9)(bend 0.9 0.9)(tjunction 0.9)(style diagonal)
miter (pin 0.7)(slant 0.7)(bend 0.7 0.7)(tjunction 0.7)(style diagonal)
miter (pin 0.5)(slant 0.5)(bend 0.5 0.5)(tjunction 0.5)(style diagonal)
miter (pin 0.3)(slant 0.3)(bend 0.3 0.3)(tjunction 0.3)(style diagonal)
miter (pin 0.1)(slant 0.1)(bend 0.1 0.1)(tjunction 0.1)(style diagonal)
miter (pin 0.075)(slant 0.075)(bend 0.075 0.075)(tjunction 0.075)(style diagonal)
miter (pin 0.050)(slant 0.05)(bend 0.05 0.05)(tjunction 0.05)(style diagonal)
miter (pin 0.025)(slant 0.025)(bend 0.025 0.025)(tjunction 0.025)(style diagonal)
miter (pin 0.0125)(slant 0.0125)(bend 0.0125 0.0125)(tjunction 0.0125)(style diagonal)
write routes $/final.wir
report status $/final.sts
