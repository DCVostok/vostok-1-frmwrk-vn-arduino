import glob
import os
import string

from SCons.Script import DefaultEnvironment

env = DefaultEnvironment()
platform = env.PioPlatform()
board = env.BoardConfig()
mcu = board.get("build.mcu", "")
variant = board.get("build.variant")


ARDUINO_PACKADGE_DIR = platform.get_package_dir("vostok-1-frmwrk-vn-arduino")
CMSIS_DIR = platform.get_package_dir("framework-cmsis")
ARDUINO_CORE_DIR = os.path.join(ARDUINO_PACKADGE_DIR, "cores", "arduino")
SDK_DIR = platform.get_package_dir("framework-k1921vk-sdk")
DEVICE_DIR = os.path.join(SDK_DIR, "platform", "Device", "NIIET", mcu)
DEVICE_SDK_DIR = ""
if mcu == "K1921VK01T":
    DEVICE_SDK_DIR = os.path.join(SDK_DIR, "platform", "niietcm4_pd")
elif mcu == "K1921VK028":
    DEVICE_SDK_DIR = os.path.join(SDK_DIR, "platform", "plib028")
elif mcu == "K1921VK035":
    DEVICE_SDK_DIR = os.path.join(SDK_DIR, "platform", "plib035")

VARIANT_DIR = os.path.join(ARDUINO_PACKADGE_DIR, "variants", variant)

env.Append(
    CPPPATH=[
        os.path.join(DEVICE_SDK_DIR, "inc"),
        os.path.join(DEVICE_SDK_DIR, "src"),
        os.path.join(DEVICE_DIR, "Source"),
        os.path.join(DEVICE_DIR, "Source", "GCC"),
        os.path.join(VARIANT_DIR),
        os.path.join(ARDUINO_CORE_DIR)
    ],
    CPPDEFINES=[
        ("F_CPU", str(board.get("build.f_cpu"))),
        ("MCU_"+mcu),  # MCU name
        ("ARDUINO_"+board.get("build.board")),
        ("ARDUINO", "10808"),
    ],
)

if not board.get("build.ldscript", ""):
    env.Replace(LDSCRIPT_PATH=os.path.join(
        DEVICE_DIR, "Source", "GCC", "%s.ld" % mcu))

env.Append(
    CPPPATH=[
        os.path.join(DEVICE_DIR, "Include"),
        os.path.join(CMSIS_DIR, "CMSIS", "Core", "Include")
    ]
)

env.Append(
    LIBSOURCE_DIRS=[
        os.path.join(ARDUINO_PACKADGE_DIR, "libraries")
    ]
)


#
# Compile arduino core sources
#

sources_path = os.path.join(ARDUINO_CORE_DIR)
env.BuildSources(
    os.path.join("$BUILD_DIR", "arduino_core"), sources_path,
    src_filter=[
        "+<*>",
        "-<framework-k1921vk-sdk*>"]

)

#
# Compile arduino variant sources
#

sources_path = os.path.join(VARIANT_DIR)
env.BuildSources(
    os.path.join("$BUILD_DIR", "arduino_variant"), sources_path,
    src_filter=[
        "+<*>"]
)
