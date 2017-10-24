import viz
import vizconnect 
import vizfx
import random
import vizact
import time
import vizproximity
import viz
import vizact
import vizcam
import vizshape
import vizconfig
import vizinfo
import viztask

import vizfx.postprocess
from vizfx.postprocess.color import GrayscaleEffect
from vizfx.postprocess.composite import BlendEffect

import math
import vizinfo
 


screen_text = viz.addText('press <b> to start the game\npress <k> to toggle the sensors\npress 1-5 for change different view point\npress <p> for to see particular landmarks',viz.SCREEN)
screen_text.setScale(0.25,0.25,0.25)
screen_text.setPosition(0,0.6,0)

viz.setMultiSample(10)
#vizconnect.go('vizconnect_config.py')
viz.go()

ground=viz.addChild('ground.osgb')
ground.setPosition([00,-0.1,0])
ground.setScale([40,40,40])

########add sun and sky##############################
sky=viz.addChild('sky_day.osgb') 
sun=vizfx.addDirectionalLight()
sun.setScale(500,500,500)
sun.color(5.0,5.0,5)
sun.setEuler(90,0,0)
sky.setPosition(500,0,500)
sky.setScale(10,10,10)

###########main view position############################
viz.MainView.move([-100,20,140])
viz.MainView.setEuler([90,0,0])
viz.MainView.gravity(0.0) 

####################sun_light#####################################################
mylight = viz.addLight()
mylight.position(0,15,0) 
mylight.direction(10,-10,-10) 
mylight.spread(9000) 
mylight.intensity(1.8) 
mylight.spotexponent(2) 
mylight.setPosition(100,120,100) 

mylight1 = viz.addLight()
mylight1.position(40,15,-10) 
mylight1.direction(10,-10,100) 
mylight1.spread(9000) 
mylight1.intensity(1.8) 
mylight1.spotexponent(2) 
mylight1.setPosition(100,120,100) 

mylight2 = viz.addLight()
mylight2.position(-100,15,40) 
mylight2.direction(15,-15,-100) 
mylight2.spread(9000) 
mylight2.intensity(1.8) 
mylight2.spotexponent(2) 
mylight2.setPosition(100,120,100) 


mylight3 = viz.addLight()
mylight3.position(100,15,136) 
mylight3.direction(10,-10,-100) 
mylight3.spread(9000) 
mylight3.intensity(1.8) 
mylight3.spotexponent(2) 
mylight3.setPosition(100,120,100) 

mylight4 = viz.addLight()
mylight4.position(-100,15,20) 
mylight4.direction(10,-10,-100) 
mylight4.spread(9000) 
mylight4.intensity(1.8) 
mylight4.spotexponent(2) 
mylight4.setPosition(-100,120,20)


mylight5 = viz.addLight()
mylight5.position(-40,15,130) 
mylight5.direction(10,-10,100) 
mylight5.spread(9000) 
mylight5.intensity(1.8) 
mylight5.spotexponent(2) 
mylight5.setPosition(100,120,100)


###################################all_avatars###################################
park_male = viz.addAvatar('vcc_male2.cfg', pos=(10,0,16.8), euler=(180,0,0) )
park_male.setScale(2,2,2)
park_male.state(6)


#custom male1
park_chid = viz.addAvatar('vcc_male2.cfg', pos=(1.5,0,-20.5), euler=(0,0,0) )
park_chid.setScale(1.5,1.5,1.5)
park_chid.state(6)


park_female = viz.addAvatar('vcc_female.cfg', pos=(3,0,-39), euler=(0,0,0) )
park_female.setScale(2,2,2)
park_female.state(10)


bus_child=viz.addChild('vcc_male2.cfg',pos=(-44,2.35,36), euler=(180,0,0))
bus_child.setScale(1.8,1.8,1.8)
bus_child.state(6)

gas_female = viz.addAvatar('vcc_female.cfg', pos=(-41.5,0,124), euler=(160,0,0))
gas_female.setScale(2,2,2)
gas_female.state(1)

#custom female2
bus_female = viz.addAvatar('vcc_female.cfg', pos=(-45.5,2,33), euler=(180,0,0) )
bus_female.setScale(2,2,2)
bus_female.state(1)


#custom male2
bus_male = viz.addAvatar('vcc_male.cfg', pos=(-45.5,2,40), euler=(180,0,0) )
bus_male.setScale(2,2,2)
bus_male.state(1)
face3 = viz.addFace('morph_head.vzf')
face3.setScale(2,2,2)
bus_male.face(face3)

driver=viz.addChild('vcc_male2.cfg',pos=(-43.8,2.35,30.2), euler=(180,0,0))
driver.setScale(1.8,1.8,1.8)
driver.state(6)
face4 = viz.addFace('morph_head.vzf')
face4.setScale(1.8,1.8,1.8)
driver.face(face4)


#custom  male3
gas_male = viz.addAvatar('vcc_male.cfg', pos=(-43.45,0,123), euler=(90,0,0))
gas_male.setScale(2,2,2)
gas_male.state(1)
face2 = viz.addFace('morph_head.vzf')
face2.setScale(2,2,2)
gas_male.face(face2)


###############################################pigeons####################################
pigeons = []
for i in range(20):
    x = random.randint(-6,19)
    z = random.randint(22,50)
    yaw = random.randint(0,360)
    pigeon = viz.addAvatar('pigeon.cfg')
    pigeon.setScale([1.5,1.5,1.5])
    pigeon.setPosition([x,0,z])
    pigeon.setEuler([yaw,0,0])
    pigeon.state(2)
    pigeons.append(pigeon)

#viz.collision(viz.OFF)

sceen = viz.addChild('only_school.dae')
sceen.setPosition(0,0,0)
city=viz.addChild('city_1.dae')
city.setPosition(80,-4.2,139)

#############################bomb_location######################

bomb_in_car=viz.addChild('bomb.dae')
bomb_in_car.setScale(2,2,2)
bomb_in_car.setPosition(-85,0.3,30)


bomb_in_smallbuilding=viz.addChild('bomb.dae')
bomb_in_smallbuilding.setScale(1,1,1)
bomb_in_smallbuilding.setPosition(70,0,-25)

police_station=viz.addChild('police_station.dae')
police_station.setPosition(75,0,-15)
police_station.setScale(1.5,2,1.5)
police_station.setEuler(90,0,0)

bomb_in_school=viz.addChild('bomb.dae')
bomb_in_school.setScale(0.5,0.5,0.5)
bomb_in_school.setPosition(-15,1,-25)

tree_in_park=viz.addChild('tree.dae')
tree_in_park.setPosition(68,0,5)
tree_in_park.setScale(2,2,2)


bench_in_park=viz.addChild('bench.dae')
bench_in_park.setPosition(60,-2,4)
bench_in_park.setScale(2,2,2)


bomb_under_bench=viz.addChild('bomb.dae')
bomb_under_bench.setScale(2,2,2)
bomb_under_bench.setPosition(63,0.2,4)


bomb_under_car_at_gas_station=viz.addChild('bomb.dae')
bomb_under_car_at_gas_station.setScale(2,2,2)
bomb_under_car_at_gas_station.setPosition(-30,0.2,126)


bomb_in_schoolbus=viz.addChild('bomb.dae')
bomb_in_schoolbus.setScale(1,1,1)
bomb_in_schoolbus.setPosition(-44,2.35,36)


trashcan=viz.addChild('trash.dae')
trashcan.setScale(0.1,0.1,0.1)
trashcan.setPosition(15,1,20)

bomb_in_trashcan=viz.addChild('bomb.dae')
bomb_in_trashcan.setScale(1.5,1.5,1.5)
bomb_in_trashcan.setPosition(15,0,25)


import vizfx.postprocess
from vizfx.postprocess.color import GrayscaleEffect
from vizfx.postprocess.composite import BlendEffect
import math
########################game######################


# Script settings
TRIAL_COUNT = 7			# Number of landmarks to find
TRIAL_DURATION = 40			# Amount of time allowed to get to each Landmark (in seconds)
TRIAL_DELAY = 2				# Delay time between trials
FLASH_TIME = 3.0			# Time to flash screen at beginning of each trial

INSTRUCTIONS = """
{} bombs are to be defused in the city. You have {} seconds to get to each of them.
Use the mouse to move around. The locations of the bombs include
a the school, school bus, trash can, by the bench etc be very observant while looking
for the bomb so you do not run out of time and blow up the city.
Press spacebar to begin the bomb defusal game!""".format(TRIAL_COUNT,TRIAL_DURATION)


RESULTS = """You found {} of {} bombs."""

TRIAL_SUCCESS = 'Bomb found!'
TRIAL_FAIL = 'Failed, Please evacuate !!'

# Add main viewpoint as proximity target
manager = vizproximity.Manager(viz.MainView)
manager.addTarget(vizproximity.Target(viz.MainView) ) 
	
# Create sensors attached to static matrix
#Bomb in car
sensor = vizproximity.Sensor(vizproximity.Sphere(15.0),source=viz.Matrix.translate(-85,0.3,30))

#Bomb in small building
sensor2 = vizproximity.Sensor(vizproximity.Sphere(15.0),source=viz.Matrix.translate(-15,0,-25))

#Bomb in school
sensor3 = vizproximity.Sensor(vizproximity.Sphere(15.0),source=viz.Matrix.translate(70,0,-20))

#Bomb under bench
sensor4 = vizproximity.Sensor(vizproximity.Sphere(15.0),source=viz.Matrix.translate(63,0.2,4))

#Bomb under car at gas station
sensor5 = vizproximity.Sensor(vizproximity.Sphere(15.0),source=viz.Matrix.translate(-30,0.2,126))


#Bomb in schoolbus
sensor6 = vizproximity.Sensor(vizproximity.Sphere(15.0),source=viz.Matrix.translate(-44,2.35,36))

#Bomb in trashcan
sensor7 = vizproximity.Sensor(vizproximity.Sphere(15.0),source=viz.Matrix.translate(15,2,25))


# Create flash screen quad
flash_quad = viz.addTexQuad(parent=viz.ORTHO)
flash_quad.color(viz.WHITE)
flash_quad.drawOrder(-10)
flash_quad.blendFunc(viz.GL_ONE,viz.GL_ONE)
flash_quad.visible(False)
flash_quad.setBoxTransform(viz.BOX_ENABLED)

# Create status bar background
status_bar = viz.addTexQuad(parent=viz.ORTHO)
status_bar.color(viz.BLACK)
status_bar.alpha(0.5)
status_bar.drawOrder(-1)
status_bar.setBoxTransform(viz.BOX_ENABLED)
status_bar.setBoxAnchor([0,1,1,1])
status_bar.setBoxOffset([0,-80,0,0])

#sound for bombs when you go near to it

hooting = bomb_in_car.playsound('beep.wav',viz.LOOP)
hooting.pause()
hooting1=bomb_in_school.playsound('beep.wav',viz.LOOP)
hooting1.pause()
hooting2=bomb_in_schoolbus.playsound('beep.wav',viz.LOOP)
hooting2.pause()
hooting3=bomb_in_smallbuilding.playsound('beep.wav',viz.LOOP)
hooting3.pause()
hooting4=bomb_in_trashcan.playsound('beep.wav',viz.LOOP)
hooting4.pause()
hooting5=bomb_under_bench.playsound('beep.wav',viz.LOOP)
hooting5.pause()
hooting6=bomb_under_car_at_gas_station.playsound('beep.wav',viz.LOOP)
hooting6.pause()

# Create time limit text
time_text = viz.addText('', parent=status_bar, fontSize=40, align=viz.ALIGN_CENTER_BOTTOM)
time_text.setBackdrop(viz.BACKDROP_OUTLINE)
time_text.setBoxTransform(viz.BOX_ENABLED)

# Create score text
score_text = viz.addText('', parent=status_bar, fontSize=40, align = viz.ALIGN_CENTER_TOP)
score_text.setBackdrop(viz.BACKDROP_OUTLINE)
score_text.setBoxTransform(viz.BOX_ENABLED)
score_text.setBoxOffset([0,0,0,0])
score_text.setPosition(400,1,0)

# Create post process effect for blending to gray scale
gray_effect = BlendEffect(None,GrayscaleEffect(),blend=0.0)
gray_effect.setEnabled(False)
vizfx.postprocess.addEffect(gray_effect)

def DisplayInstructionsTask():
	"""Task that display instructions and waits for keypress to continue"""
	panel = vizinfo.InfoPanel(INSTRUCTIONS,align=viz.ALIGN_CENTER,fontSize=22,icon=False,key=None)
	yield viztask.waitKeyDown(' ')
	panel.remove()
	
def sensors():
	manager.addSensor(sensor)
	manager.addSensor(sensor2)
	manager.addSensor(sensor3)
	manager.addSensor(sensor4)
	manager.addSensor(sensor5)
	manager.addSensor(sensor6)
	manager.addSensor(sensor7)
	
	
def TrialCountDownTask():
	"""Task that count downs to time limit for trial"""
	# Action for text fading out
	text_fade = vizact.parallel(
		vizact.fadeTo(0,time=0.8,interpolate=vizact.easeOut)
		,vizact.sizeTo([1.5,1.5,1.0],time=0.8,interpolate=vizact.easeOut)
	)
	
	# Reset time text
	time_text.clearActions()
	time_text.alpha(1.0)
	time_text.color(viz.WHITE)
	time_text.setScale([1,1,1])
	time_text.message(str(int(TRIAL_DURATION)))
		
	# Countdown from time limit	
	start_time = viz.getFrameTime()
	last_remain = int(TRIAL_DURATION)
	while (viz.getFrameTime() - start_time) < TRIAL_DURATION:
				# Compute remaining whole seconds
		remain = int(math.ceil(TRIAL_DURATION - (viz.getFrameTime() - start_time)))
				# Update text if time remaining changed
		if remain != last_remain:
			if remain <= 5:
				time_text.alpha(1.0)
				time_text.color(viz.RED)
				time_text.setScale([1]*3)
				time_text.runAction(text_fade)
				viz.playSound('sounds/beep.wav')
			time_text.message(str(remain))
			last_remain = remain

		# Wait tenth of second
		yield viztask.waitTime(0.1)
	

def FlashScreen():
	"""Flash screen and fade out"""
	flash_quad.visible(True)
	flash_quad.color(viz.WHITE)
	fade_out = vizact.fadeTo(viz.BLACK,time=FLASH_TIME,interpolate=vizact.easeOutStrong)
	flash_quad.runAction(vizact.sequence(fade_out,vizact.method.visible(False)))

def FadeToGrayTask():
	gray_effect.setBlend(0.0)
	gray_effect.setEnabled(True)
	yield viztask.waitCall(gray_effect.setBlend,vizact.mix(0.0,1.0,time=1.0))

def UpdateScore(score):
	"""Update score text"""
	score_text.message('Found: {} / {} bombs'.format(score,TRIAL_COUNT))
	
	if score == 10:
		score_text.visible(viz.OFF)
	
def remove(resultPanel):
	resultPanel.remove()

def TrialTask():
	"""Task for individual trial. Returns whether BOMB was found."""

	# Flash screen
	FlashScreen()

	# Wait until BOMB is found or time runs out
	wait_time = viztask.waitTask( TrialCountDownTask() )
	wait_find = vizproximity.waitEnter(sensor)
	#print wait_find	
	wait_find2 = vizproximity.waitEnter(sensor2)
	wait_find3 = vizproximity.waitEnter(sensor3)
	wait_find4 = vizproximity.waitEnter(sensor4)
	wait_find5 = vizproximity.waitEnter(sensor5)
	wait_find6 = vizproximity.waitEnter(sensor6)
	wait_find7 = vizproximity.waitEnter(sensor7)
	data = yield viztask.waitAny([wait_time,wait_find, wait_find2, wait_find3, wait_find4, wait_find5, wait_find6, wait_find7])

	if data.condition == wait_find:
		manager.removeSensor(sensor)
	
	elif data.condition == wait_find2:
		manager.removeSensor(sensor2)
		
	elif data.condition == wait_find3:
		manager.removeSensor(sensor3)
		
	elif data.condition == wait_find4:
		manager.removeSensor(sensor4)
		
	elif data.condition == wait_find5:
		manager.removeSensor(sensor5)
		
	elif data.condition == wait_find6:
		manager.removeSensor(sensor6)
		
	elif data.condition == wait_find7:
		manager.removeSensor(sensor7)
		
		
	# Return whether bomb was found
	viztask.returnValue(data.condition is wait_find or data.condition is wait_find2 or data.condition is wait_find3
	or data.condition is wait_find4 or data.condition is wait_find5 or data.condition is wait_find6 or data.condition is wait_find7)

def MainTask():
	"""Top level task that controls the game"""

	# Display instructions and wait for key press to continue
	yield DisplayInstructionsTask()
	tracker = vizcam.addWalkNavigate(moveScale=2.0)
	tracker.setPosition([0,2.5,0])
	viz.link(tracker,viz.MainView)
	viz.mouse.setVisible(False)
	
	# Create panel to display trial results
	resultPanel = vizinfo.InfoPanel('',align=viz.ALIGN_CENTER,fontSize=25,icon=False,key=None)
	resultPanel.visible(False)

	# Reset score
	score = 0
	UpdateScore(score)
	sensors()
	found = True
	number = 0
	
				
	while found and number < 7:
		# Perform a trial
		found = False
		found = yield TrialTask()

		# Update score and display status text
		if found :
			score += 1
			UpdateScore(score)	
			resultPanel.setText(TRIAL_SUCCESS)	
				
		else:
			viztask.schedule(FadeToGrayTask())
			resultPanel.setText(TRIAL_FAIL)
			viz.mouse.setVisible(True)
			Run_function()
			

		#Display success/failure message
		resultPanel.visible(True)

		# Add delay before starting next trial
		yield viztask.waitTime(TRIAL_DELAY)
		resultPanel.visible(False)
		number += 1

	# Disable gray effect
	gray_effect.setEnabled(False)

	#Display results and ask to quit or play again
	resultPanel.setText(RESULTS.format(score,TRIAL_COUNT))
	resultPanel.visible(True)
	yield viztask.waitTime(5)
	resultPanel.visible(False)
	UpdateScore(10)
	
#viz.MainView.collision( viz.ON )

def startLandmark():
	viztask.schedule( MainTask() )
	
	
	#Setup keyboard/mouse tracker
	
	
vizact.onkeydown('b', startLandmark)
viz.mouse.setVisible(True)



#############plant_location#################33

plant2=viz.addChild('plant.osgb')
plant2.setScale(3,3,3)
plant2.setPosition(-14.5,0,-35)

plant3=viz.addChild('plant.osgb')
plant3.setScale(3,3,3)
plant3.setPosition(-14.5,0,-25)

plant6=viz.addChild('plant.osgb')
plant6.setScale(3,3,3)
plant6.setPosition(-110,0,-35)


plant5=viz.addChild('plant.osgb')
plant5.setScale(3,3,3)
plant5.setPosition(-90,0,-30)

plant7=viz.addChild('plant.osgb')
plant7.setScale(3,3,3)
plant7.setPosition(-52,0,-30)



#######################sound############################

#Adding sound
sound = viz.addAudio('radio2.mp3') 
#sound.loop(viz.ON) 
sound.volume(2) 
sound.setTime(3) 
sound.setRate(1) 
sound.play()

########################################################

speech = vizact.speak('jfk.wav')

run11 = vizact.walkTo([-45,2.40,30.5],verb='run')
run21 = vizact.walkTo([-45,2.40,30.5],verb='run')
run31 = vizact.walkTo([-45,2.40,30.5],verb='run')
run41 = vizact.walkTo([-42,2.40,30.5],verb='run')


run12 = vizact.walkTo([-48,0,29],verb='run')
run22 = vizact.walkTo([-49,0,28],verb='run')
run32 = vizact.walkTo([-49,0,27],verb='run')
run42 = vizact.walkTo([-42,0,30],verb='run')


run13 = vizact.walkTo([-45,0,-59],verb='run')
run23 = vizact.walkTo([-46,0,-59],verb='run')
run33 = vizact.walkTo([-47,0,-59],verb='run')
run43 = vizact.walkTo([-42,0,-59],verb='run')


run5 = vizact.walkTo([-155,0,-20],verb='run')
run6 = vizact.walkTo([-160,0,-25],verb='run')
run7 = vizact.walkTo([-155,0,-50],verb='run')
run8 = vizact.walkTo([-155,0,-52],verb='run')
run9 = vizact.walkTo([-159,0,-10],verb='run')
	
	
def Run_function():	
	sceen_after_gamefailure()
	
	bus_child.addAction(run11)
	time.sleep(0.5)
	
	bus_child.state(7)
	bus_child.addAction(run12)
	bus_child.addAction(run13)

	bus_female.addAction(run21)
	bus_female.state(7)
	bus_female.addAction(run22)
	bus_female.addAction(run23)
	
	bus_male.addAction(run31)
	bus_male.state(7)
	bus_male.addAction(run32)
	bus_male.addAction(run33)
	
	time.sleep(2)
	
	#driver.addAction(run41)
	#driver.addAction(run42)
	driver.addAction(run43)
	
	bus_child.speed(0.5)
	bus_female.speed(0.6)
	bus_male.speed(2)	
	driver.speed(1)
	
	park_chid.addAction(run5)
	park_female.addAction(run6)
	park_male.addAction(run9)
	gas_female.addAction(run7)
	gas_male.addAction(run8)	
	
	gas_male.speed(1)
	gas_female.speed(1)
	park_female.speed(1)
	park_male.speed(1)

#AVTARS WILL START RUNNING..........
#vizact.onkeydown('r',Run_function)

#avatar will begin speaking when the l key is pressed
vizact.onkeydown('l', bus_male.addAction, speech)




#########################fire and smoke location##########################
def sceen_after_gamefailure():
	#smoke at buildings
	
	blast_sound1= viz.addAudio('SPEECH.MP3') 
	blast_sound1.loop(viz.ON) 
	blast_sound1.volume(2) 
	blast_sound1.setTime(3) 
	blast_sound1.setRate(1) 
	blast_sound1.play()

	smoke1=viz.addChild('smoke.dae')
	fire_1=viz.addChild('fire2.dae')
	fire_1.setPosition(-85,60,260)
	fire_1.setScale(2,2,2)
	smoke1.setScale(1,1,1)
	smoke1.setPosition(-85,65,250)
	time.sleep(0.1)
	
	blast_sound = viz.addAudio('explosion.wav') 
	blast_sound.loop(viz.ON) 
	blast_sound.volume(.2) 
	blast_sound.setTime(3) 
	blast_sound.setRate(1) 
	blast_sound.play()

	smoke3=viz.addChild('smoke.dae')
	fire_3=viz.addChild('fire2.dae')
	fire_3.setPosition(65,60,260)
	fire_3.setScale(2,2,2)
	smoke3.setScale(1,1,1)
	smoke3.setPosition(65,65,255)
	time.sleep(0.1)

	#smoke near to car
	smoke2=viz.addChild('smoke.dae')
	fire_2=viz.addChild('fire2.dae')
	fire_2.setScale(0.3,0.4,0.3)
	fire_2.setPosition(-85,2,34)
	smoke2.setScale(0.1,0.2,0.3)
	smoke2.setPosition(-85,1,35)
	time.sleep(0.1)
	
	blast_sound1 = viz.addAudio('explosion.wav') 
	blast_sound1.loop(viz.ON) 
	blast_sound1.volume(.5) 
	blast_sound1.setTime(3) 
	blast_sound1.setRate(1) 
	blast_sound1.play()

	#smoke at small building
	smoke4=viz.addChild('smoke.dae')
	smoke4.setScale(0.3,0.2,0.3)
	smoke4.setPosition(29,17,110)
	fire_4=viz.addChild('fire2.dae')
	fire_4.setScale(0.3,0.7,0.3)
	fire_4.setPosition(29,15,110)
	time.sleep(0.1)



	fire_in_schoolbus=viz.addChild('fire2.dae')
	fire_in_schoolbus.setScale(0.2,0.15,0.2)
	fire_in_schoolbus.setPosition(-46,3,49)


	#fire near to park
	smoke5=viz.addChild('smoke.dae')
	smoke5.setScale(0.3,0.3,0.3)
	smoke5.setPosition(68,0.5,5)
	fire_5=viz.addChild('fire2.dae')
	fire_5.setScale(0.3,0.5,0.3)
	fire_5.setPosition(68,0,5)
	time.sleep(0.1)

	blast_sound2 = viz.addAudio('explosion.wav') 
	blast_sound2.loop(viz.ON) 
	blast_sound2.volume(.2) 
	blast_sound2.setTime(3) 
	blast_sound2.setRate(1) 
	blast_sound2.play()

	#fire at the gas station
	fire=viz.addChild('fire2.dae')
	fire.setScale(0.3,0.6,0.3)
	fire.setPosition(-46,0,136)

	fire1=viz.addChild('smoke.dae')
	fire1.setScale(0.3,0.3,0.3)
	fire1.setPosition(-46,5,156)
	
	sound1 = viz.addAudio('burning1.wav') 
	sound1.loop(viz.ON) 
	sound1.volume(.3) 
	sound1.setTime(3) 
	sound1.setRate(1) 
	sound1.play()
	time.sleep(0.8)
	
	sound2 = viz.addAudio('firetrucks.wav') 
	sound2.loop(viz.ON) 
	sound2.volume(.2) 
	sound2.setTime(3) 
	sound2.setRate(1) 
	sound2.play()

	fire3=viz.addChild('fire2.dae')
	fire3.setScale(0.2,0.6,0.2)
	fire3.setPosition(-46,10,156)

	fire4=viz.addChild('fire2.dae')
	fire4.setScale(0.3,0.4,0.2)
	fire4.setPosition(-66,0,136)

###########################WINDOWS VIEW###############################################

"""
This script demonstrates how to add multiple windows.
The upper right window is a rear view of the scene
The upper left window is a birds eye view
"""

import viz
import vizact

viz.setMultiSample(4)
viz.fov(60)
viz.go()

import vizinfo

# Create a new window in the upper left corner
UpperLeftWindow = viz.addWindow(pos=(0,1.0),size=(0.2,0.2))

#Create a new window in the upper right corner
UpperRightWindow = viz.addWindow(pos=(0.7,1.0),size=(0.2,0.2))

# Create a new viewpoint
BirdView = viz.addView()

#Attach the bird's eye view to the upper left window
UpperLeftWindow.setView(BirdView)

#Move the view above the center of the room
BirdView.setPosition([0,500,0])

#Rotate the view so that it looks down
BirdView.setEuler([0,90,0])

#Create another viewpoint
RearView = viz.addView()

#Attach the rear view to the upper right window
UpperRightWindow.setView(RearView)

#Increase the field-of-view for both windows
UpperLeftWindow.fov(60)
UpperRightWindow.fov(60)

#Add an arrow marker to bird's eye view window to represent our current position/orientation
arrow = viz.addTexQuad(parent=viz.ORTHO,scene=UpperLeftWindow,size=20)
arrow.texture(viz.add('arrow.tif'))

def UpdateViews():

	#Get the current head orientation and position
	yaw,pitch,roll = viz.MainView.getEuler()
	pos = viz.MainView.getPosition()

	#Move the rear view to the current position
	RearView.setPosition(pos)

	#Rotate the rear view so that it faces behind us
	RearView.setEuler([yaw+180,0,0])

	#Move arrow to our current location
	x,y,z = UpperLeftWindow.worldToScreen(pos,mode=viz.WINDOW_PIXELS)
	arrow.setPosition([x,y,0])
	arrow.setEuler([0,0,-yaw])

vizact.ontimer(0,UpdateViews)

######################################animated view#############################################

def AnimateView1():
	
	viz.MainView.move([110,10,-150])
	viz.MainView.setEuler([90,0,0])
		
def AnimateView2():
	
	viz.MainView.move([120,10,180])
	viz.MainView.setEuler([90,0,0])
		
def AnimateView3():
	
	viz.MainView.move([-130,20,200])
	viz.MainView.setEuler([90,0,0])
		
def AnimateView4():
	
	viz.MainView.move([-200,20,-200])
	viz.MainView.setEuler([90,0,0])
	
def AnimateView5():

	viz.MainView.move([0,20,0])
	viz.MainView.setEuler([90,0,0])
	
def AnimateView6():
	camera = vizcam.addKeyboard6DOF()
	camera.setPosition([0,2,0])
	
camera = vizcam.addKeyboard6DOF()
camera.setPosition([0,2,0])
#Setup keyboard events
vizact.onkeydown('1',AnimateView1)
vizact.onkeydown('2',AnimateView2)
vizact.onkeydown('3',AnimateView3)
vizact.onkeydown('4',AnimateView4)
vizact.onkeydown('5',AnimateView5)
vizact.onkeydown('6',AnimateView6)
#############################EXPLAINING LANDMARKS########################
def textScreen1():
	textScreen = viz.addText('This is a new public school. students in this school are very intelligent',viz.SCREEN)
	textScreen.alignment(viz.ALIGN_RIGHT_BOTTOM)
	textScreen.setScale(0.2,0.2,0.2)
	textScreen.setPosition([0.95,0.05,0])


def textScreen2():
		
	textScreen = viz.addText('school bus, students who are travelling in this bus are rich and excellent in studies',viz.SCREEN)
	textScreen.alignment(viz.ALIGN_RIGHT_BOTTOM)
	textScreen.setPosition([0.95,0.05,0])
	
fadeInOut = vizact.sequence(vizact.fadeTo(1,time=1),vizact.waittime(4),vizact.fadeTo(0,time=1))

	
def landmark():

	object = viz.pick();
	
	if object.valid() and object == bomb_in_school:
		textbox1 = viz.addTextbox()
		#Make it twice as long. 
		textbox1.length(2) 
		textbox1.setPosition(.5,.5) 
		#Have it grow when text reaches its boundary. 

		textbox1.overflow(viz.OVERFLOW_GROW) 

		textbox1.message('you are at the public school')

		textbox1.add(fadeInOut)

			

	elif object.valid() and object == bomb_in_trashcan:

		textbox1 = viz.addTextbox() 

		#Make it twice as long. 

		textbox1.length(2) 

		textbox1.setPosition(.5,.5) 

		#Have it grow when text reaches its boundary. 

		textbox1.overflow(viz.OVERFLOW_GROW) 

		textbox1.message('you are at the park')

		textbox1.add(fadeInOut)

		

	elif object.valid() and object == police_station:

		textbox1 = viz.addTextbox() 

		#Make it twice as long. 

		textbox1.length(2) 

		textbox1.setPosition(.5,.5) 

		#Have it grow when text reaches its boundary. 

		textbox1.overflow(viz.OVERFLOW_GROW) 

		textbox1.message('you are at the police station')

		textbox1.add(fadeInOut)

		
		

	elif object.valid() and object == bomb_in_schoolbus:

		textbox1 = viz.addTextbox() 

		#Make it twice as long. 

		textbox1.length(2) 

		textbox1.setPosition(.5,.5) 

		#Have it grow when text reaches its boundary. 

		textbox1.overflow(viz.OVERFLOW_GROW) 

		textbox1.message('you are near to school bus')

		textbox1.add(fadeInOut)
		

	elif object.valid() and object == bomb_under_car_at_gas_station:

		textbox1 = viz.addTextbox() 

		#Make it twice as long. 

		textbox1.length(2) 

		textbox1.setPosition(.5,.5) 

		#Have it grow when text reaches its boundary. 

		textbox1.overflow(viz.OVERFLOW_GROW) 

		textbox1.message('you are  at the gas station')

		textbox1.add(fadeInOut)


vizact.onmousedown(viz.MOUSEBUTTON_LEFT, landmark)
	


vizact.onkeydown('p',landmark)
###############################sensor visible#############################

#Create sensors for destinations
bomb_in_trashcan1 = vizproximity.Sensor(vizproximity.Box([4,5,5],center=[0,2.5,0]),source=bomb_in_trashcan)
bomb_in_school1 = vizproximity.Sensor(vizproximity.Box([5,4,4],center=[0,1.7,0]),source=bomb_in_school)

#Add main viewpoint as proximity target
target = vizproximity.Target(viz.MainView)

#Create proximity manager
manager1 = vizproximity.Manager()

#Add destination sensors to manager
manager1.addSensor(bomb_in_trashcan1)
manager1.addSensor(bomb_in_school1)

#Add viewpoint target to manager
manager1.addTarget(target)

#Toggle debug shapes with keypress
vizact.onkeydown('k',manager1.setDebug,viz.TOGGLE)
