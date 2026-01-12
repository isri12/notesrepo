## 1. Cluster Architecture, Installation & Configuration (25%)

This section tests your ability to **build, configure, and manage Kubernetes clusters** using `kubeadm` and core Kubernetes components.

### Manage Role-Based Access Control (RBAC)

RBAC is essential for managing access to cluster resources. Here’s how to create a role and bind it to a service account:

```bash
kubectl create role cm-writer --verb=create --resource=configmaps -n dev
kubectl create rolebinding writer-bind --role=cm-writer --serviceaccount=dev:app-sa -n dev
kubectl auth can-i create configmap --as system:serviceaccount:dev:app-sa -n dev
```

### Prepare Underlying Infrastructure

Before setting up Kubernetes, you must prepare your underlying infrastructure. Here’s how to configure the node and disable swap:

```bash
hostnamectl set-hostname control-plane-node
echo "10.0.0.2 worker-node" >> /etc/hosts
swapoff -a
```

This prepares the system to host Kubernetes components.

### Create and Manage Clusters (kubeadm)

To initialize the Kubernetes control plane and deploy a network plugin, use the following commands:

```bash
kubeadm init --pod-network-cidr=192.168.0.0/16
kubectl apply -f https://raw.githubusercontent.com/projectcalico/calico/v3.28.0/manifests/calico.yaml
```

To join worker nodes:

```bash
kubeadm join <CONTROL_PLANE_IP>:6443 --token <TOKEN> --discovery-token-ca-cert-hash sha256:<HASH>
```

### Manage Cluster Lifecycle

You’ll need to manage your cluster lifecycle, including upgrades. Here’s how to upgrade the cluster to **v1.33**:

```bash
kubeadm upgrade plan
kubeadm upgrade apply v1.33.1
kubelet --version
```

These commands allow you to upgrade your Kubernetes version to the latest stable release.

### Configure HA Control Plane

High availability (HA) for the control plane is essential for production environments. Here’s how to set up a highly available control plane:

```bash
kubeadm init --control-plane-endpoint "LOADBALANCER_DNS:6443" --upload-certs
```

To add an additional control-plane node:

```bash
kubeadm join LOADBALANCER_DNS:6443 --control-plane --token <TOKEN> --discovery-token-ca-cert-hash sha256:<HASH> --certificate-key <CERT_KEY>
```

### Helm & Kustomize

Helm is a Kubernetes package manager that simplifies application deployment. Kustomize helps you manage configurations. Here’s how you can deploy **nginx** using Helm and apply custom configurations using Kustomize:

```bash
helm repo add bitnami https://charts.bitnami.com/bitnami
helm install nginx bitnami/nginx
kubectl apply -k ./my-kustomization/
```

### CNI / CSI / CRI

Container Network Interface (CNI), Container Storage Interface (CSI), and Container Runtime Interface (CRI) are crucial for network and storage management. Here’s how to verify the CNI configuration and check for available storage drivers:

```bash
crictl info
ls /etc/cni/net.d/
kubectl get csidrivers
```

These commands help you manage and troubleshoot networking and storage drivers in Kubernetes.

### CRDs & Operators

Custom Resource Definitions (CRDs) and Operators help extend Kubernetes capabilities. To interact with CRDs and manage an operator like **Prometheus**, use the following commands:

```bash
kubectl get crds
kubectl describe crd <customresource>
kubectl apply -f https://github.com/prometheus-operator/prometheus-operator/releases/download/v0.70.0/bundle.yaml
```

### New for v1.33 — In-Place Resize & Debugging

Kubernetes v1.33 introduces **in-place pod resizing**—allowing you to increase resources without restarting the pod. Additionally, debugging has improved with tools like `kubectl debug`:

```bash
kubectl patch pod mypod --subresource=resize --type=merge   -p '{"spec":{"containers":[{"name":"app","resources":{"limits":{"cpu":"1","memory":"512Mi"}}}]}}'
kubectl debug pod/mypod -it --image=busybox --target=app -- sh
```

These features make it easier to manage resources dynamically and debug issues on the fly without downtime.
---------------
 Mumshad Mannambeth Certified Kubernetes Administrator (CKA) with Practice Tests
udemy.com/course/certified-kubernetes-administrator-with-practice-tests/  
https://github.com/kodekloudhub/certified-kubernetes-administrator-course?tab=readme-ov-file 

02-Core-Concepts

01-Core-Concepts-Section-Introduction
02-Cluster-Architecture
03-Docker-vs-ContainerD
04-ETCD-For-Beginners
05-ETCD-in-Kubernetes
06-Kube-API-Server
07-Kube-Controller-Manager
08-Kube-Scheduler
09-Kubelet
10-Kube-Proxy
11-Pods
12-Practice-Test-Introduction
13-Practice-Test-PODs
14-ReplicaSets
15-Practice-Tests-ReplicaSet
16-Deployments
17-Practice-Tests-Deployments
18-Namespaces
19-Practice-Test-Namespaces
20-Services
21-Services-ClusterIP
22-Practice-Test-Services
23-Imperative-Commands-with-kubectl
24-Practice-Test-Imperative-Commands
25-Attachments

---

## **Study Guide & Practice — Cluster Architecture, Installation & Configuration (25%)** ✅

**Overview:** Focus on kubeadm-based cluster installation, control plane components, HA, node prep, lifecycle management, networking (CNI), storage (CSI), CRDs/operators, and debugging tools.

### 🔧 Key Concepts (what to memorize)
- **Control plane components:** `kube-apiserver`, `kube-controller-manager`, `kube-scheduler`, **etcd** (data store).
- **Node components:** `kubelet`, `kube-proxy`, container runtime (containerd / Docker shim).
- **HA pattern:** load-balancer endpoint + multiple control-planes + shared/external etcd.
- **kubeadm basics:** `kubeadm init`, `kubeadm join`, `--control-plane-endpoint`, `--upload-certs` / `--certificate-key` for adding control-plane nodes.

### ⚙️ Essential Commands (cheat-sheet)
```
# Initialize control plane with pod CIDR
kubeadm init --pod-network-cidr=192.168.0.0/16

# Install Calico network plugin
kubectl apply -f https://raw.githubusercontent.com/projectcalico/calico/v3.28.0/manifests/calico.yaml

# Join a worker node
kubeadm join <CONTROL_PLANE_IP>:6443 --token <TOKEN> --discovery-token-ca-cert-hash sha256:<HASH>

# HA init with upload-certs
kubeadm init --control-plane-endpoint "LOADBALANCER_DNS:6443" --upload-certs

# Add control plane node
kubeadm join LOADBALANCER_DNS:6443 --control-plane --token <TOKEN> --discovery-token-ca-cert-hash sha256:<HASH> --certificate-key <CERT_KEY>

# Upgrade plan and apply
kubeadm upgrade plan
kubeadm upgrade apply v1.33.1
kubelet --version

# RBAC and testing
kubectl create role cm-writer --verb=create --resource=configmaps -n dev
kubectl create rolebinding writer-bind --role=cm-writer --serviceaccount=dev:app-sa -n dev
kubectl auth can-i create configmap --as system:serviceaccount:dev:app-sa -n dev

# Networking/runtime checks
crictl info
ls /etc/cni/net.d/
kubectl get csidrivers
```

### 🧪 Practice Labs (do these under a time limit)
1. **Single control-plane cluster:** init control-plane, join 2 workers, install Calico, deploy nginx, verify pod network and service.
2. **HA control-plane:** configure a simple load-balancer (HAProxy or MetalLB simulation), add a 2nd control-plane node with `--control-plane`.
3. **Upgrade practice:** drain a worker, upgrade kubelet, uncordon, verify workloads. Run `kubeadm upgrade plan` and simulate the control-plane upgrade.
4. **RBAC lab:** create Role + RoleBinding for a service account and verify with `kubectl auth can-i`.

### 🔎 Debugging & v1.33 features
- Use `kubectl debug` to troubleshoot pods with ephemeral containers.
- In-place resize (v1.33): `kubectl patch pod mypod --subresource=resize -p '{"spec":...}'` to increase resources without restart.
- Use `kubectl logs`, `kubectl describe`, `crictl` and `journalctl -u kubelet` for root-cause analysis.

### ✍️ Exam Tips
- Always prepare nodes (swapoff, hostnames, /etc/hosts updates, container runtime) before `kubeadm init`.
- Practice the exact `kubeadm` flags for HA and `join` operations — exam questions are detail-oriented.
- Timebox practice labs to 15–20 minutes each and practice diagnosing failures quickly.

---

*Study guide created from course notes and practice labs — let me know if you want me to expand any lab into step-by-step commands or add screenshots.*