# NOTE: Has to be in bbappend itself because BitBake does not fully
#       parse recipes when checking it
COMPATIBLE_MACHINE:virtio-aarch64 = "virtio-aarch64"

# Reuse base qemuarm64 machine to avoid needing our own kernel metadata
KMACHINE:virtio-aarch64 = "qemuarm64"