This comprehensive list of services defines the "boundaries" of your **AIF-C01** exam. While you don't need to be a developer for all of them, you must understand their **primary business function** and how they fit into an AI/ML workflow.

Since your exam is coming up in April 2026, I've highlighted the most critical "exam-ready" connections between these services below.

---

## 🤖 Core AI/ML "Power Players"
These services represent the bulk of the exam questions.

| Service | Primary Business Function (The "Why") |
| :--- | :--- |
| **Amazon Bedrock** | The easiest way to build GenAI apps using Foundation Models (FMs). |
| **Amazon SageMaker AI** | The platform for building, training, and deploying custom models. |
| **Amazon Q Business** | An AI assistant that answers questions based on **your company’s data**. |
| **Amazon Q Developer** | An AI assistant that helps **write and debug code** in the IDE. |
| **Amazon Nova** | AWS's newest family of multimodal models (Micro, Lite, Pro, Premier). |

---

## 🛠️ Task-Specific "Ready-to-Use" AI
AWS often asks: "Which service should you use to [X]?"

* **Vision:** **Amazon Rekognition** (Identify objects, faces, or inappropriate content in images/video).
* **Text/NLP:** * **Amazon Comprehend:** Analyze sentiment (Is the customer happy?) or extract key phrases.
    * **Amazon Textract:** Extract text from scanned PDFs or forms (not just OCR, but data tables).
* **Speech/Language:**
    * **Amazon Polly:** Text-to-Speech (Give your app a voice).
    * **Amazon Transcribe:** Speech-to-Text (Create subtitles or call center transcripts).
    * **Amazon Translate:** Multilingual translation (Uses **BLEU** scores for quality).
* **Customer Engagement:** **Amazon Lex** (The "brain" behind chatbots/Alexa).

---

## 🔐 Security, Compliance, and Data
Since you are also studying for the **Security+**, pay close attention to these "AI Security" links:

* **Amazon Macie:** Uses AI to scan your **S3 buckets** for sensitive data (PII) like social security numbers.
* **AWS KMS:** Used to encrypt your training data and model artifacts at rest.
* **Amazon Guardrails (for Bedrock):** The "Firewall" for your LLM—filters harmful content and redacts PII.
* **Amazon Augmented AI (A2I):** Implements a **"Human-in-the-loop"** to review low-confidence AI predictions.

---

## 📊 Data & Analytics "Pipelines"
AI is only as good as the data you feed it.
* **AWS Glue:** Prepares and "cleans" data (ETL) before you train a model.
* **Amazon OpenSearch Service:** The primary choice for the **Vector Database** in a RAG workflow.
* **Amazon QuickSight:** Used to visualize the results of your AI's predictions (e.g., a dashboard showing sales forecasts).

---

## 💡 AIF-C01 Study Strategy: Cross-Service Scenarios
1.  **The "Call Center" Case:** Use **Transcribe** (voice to text) $\rightarrow$ **Comprehend** (sentiment analysis) $\rightarrow$ **QuickSight** (dashboard for managers).
2.  **The "Secure Doc" Case:** Use **Textract** (read the PDF) $\rightarrow$ **Macie** (check for PII) $\rightarrow$ **S3** (securely store with **KMS**).
3.  **The "Custom Assistant" Case:** Use **Bedrock Knowledge Bases** (RAG) + **Amazon Q Business** to let employees search internal HR policies.

As we move toward your exam date, would you like to dive deeper into how **Amazon Q Business** differs from **Amazon Q Developer**? This is a very common point of confusion on the 2026 exam.

-------------------------------------------------------------

For the **AWS Certified AI Practitioner (AIF-C01)** exam, you need to be familiar with a specific set of services. These range from high-level AI services (ready to use) to foundational infrastructure.

Here is the complete list of in-scope AWS services, categorized as they appear in the official exam guide.

### 🤖 Machine Learning & Generative AI (Core)
These are the "star" services of the exam. You should know their primary use cases.
* **Amazon Bedrock:** Managed service for Foundation Models (FMs); includes Knowledge Bases (RAG), Agents, and Guardrails.
* **Amazon SageMaker AI:** The platform for building, training, and deploying custom ML models.
* **Amazon Nova:** The newest AWS-native multimodal foundation models.
* **Amazon Q Business:** AI-powered assistant for employees to interact with company data.
* **Amazon Q Developer:** AI-powered assistant for coding and technical tasks.
* **Amazon Augmented AI (A2I):** Human-in-the-loop review for AI predictions.

### 🖼️ Task-Specific AI Services (Pre-built)
* **Amazon Rekognition:** Computer vision (labels, faces, content moderation).
* **Amazon Comprehend:** Natural Language Processing (NLP) for sentiment and keyphrase extraction.
* **Amazon Textract:** Intelligent document data extraction (OCR + forms/tables).
* **Amazon Transcribe:** Speech-to-text (transcriptions).
* **Amazon Polly:** Text-to-speech (realistic voices).
* **Amazon Translate:** Language translation (uses BLEU scores).
* **Amazon Lex:** Conversational AI (building chatbots).
* **Amazon Kendra:** Enterprise search service.
* **Amazon Personalize:** Real-time recommendations.
* **Amazon Fraud Detector:** Identifying potentially fraudulent activity.

### 🔐 Security, Identity, & Compliance
* **AWS IAM:** Managing access to AI services.
* **Amazon Macie:** Using AI to find sensitive data (PII) in S3.
* **AWS KMS:** Encrypting models and training data.
* **AWS Artifact & Audit Manager:** Compliance reports and evidence.
* **Amazon Inspector:** Vulnerability scanning.
* **AWS Secrets Manager:** Managing API keys and credentials.

### 📊 Analytics & Data
* **Amazon OpenSearch Service:** Often used as the **Vector Database** for RAG.
* **AWS Glue & Glue DataBrew:** Preparing and cleaning data (ETL).
* **Amazon QuickSight:** Visualizing AI insights and forecasts.
* **Amazon Redshift:** Data warehousing with ML capabilities.
* **AWS Data Exchange:** Finding third-party datasets for training.
* **Amazon EMR & AWS Lake Formation:** Big data and data lake management.

### ☁️ Foundational Infrastructure
* **Compute:** Amazon EC2 (specifically **P-instances** and **G-instances** for training/inference).
* **Storage:** Amazon S3 (the "home" for datasets and `model.tar.gz` files).
* **Containers:** Amazon ECS & Amazon EKS (deploying models in containers).
* **Database:** DynamoDB, RDS, Neptune, and Aurora.
* **Networking:** Amazon VPC (PrivateLink for secure AI traffic) and Amazon CloudFront.

### 📈 Management & Governance
* **Amazon CloudWatch:** Monitoring model performance and logs.
* **AWS CloudTrail:** Auditing "who did what" with your AI resources.
* **AWS Config:** Tracking resource configurations.
* **AWS Budgets & Cost Explorer:** Managing the high costs of model training.
* **AWS Trusted Advisor & Well-Architected Tool:** Best practices for AI workloads.

**Final Tip for your April Exam:** Pay closest attention to the difference between **Amazon Q Business** (searching company docs) and **Amazon Q Developer** (writing code). This is a frequent point of comparison in the 2026 version of the exam.
----------------------

**AWS Trusted Advisor**
AWS Trusted Advisor is a service that provides guidance to help you provision your resources following AWS best practices. It helps optimize your AWS environment in areas such as cost savings, performance, security, and fault tolerance, making it an essential tool for governance in AI systems.

**AWS Config**
- AWS Config is a service for assessing, auditing, and evaluating the configurations of your AWS resources. It helps with continuous monitoring and compliance but does not provide the broad optimization and guidance offered by AWS Trusted Advisor.

**AWS Audit Manager**
 - AWS Audit Manager helps you continuously audit your AWS usage to assess risk and compliance with regulations and industry standards. It focuses on compliance reporting rather than providing optimization and guidance.

**AWS CloudTrail**
 - AWS CloudTrail records AWS API calls and delivers log files for auditing purposes. While it is essential for tracking user activity and compliance, it does not offer the optimization and best practice recommendations provided by AWS Trusted Advisor.

Reference:
https://aws.amazon.com/premiumsupport/technology/trusted-advisor/

AWS Audit Manager

AWS Audit Manager helps automate the collection of evidence to continuously audit your AWS usage. It simplifies the process of assessing risk and compliance with regulations and industry standards, making it an essential tool for governance in AI systems.

AWS Artifact - AWS Artifact provides on-demand access to AWS’ compliance reports and online agreements. It is useful for obtaining compliance documentation but does not provide continuous auditing or automated evidence collection.

AWS Trusted Advisor - AWS Trusted Advisor offers guidance to help optimize your AWS environment for cost savings, performance, security, and fault tolerance. While it provides recommendations for best practices, it does not focus on auditing or evidence collection for compliance.

AWS CloudTrail - AWS CloudTrail records AWS API calls for auditing purposes and delivers log files for compliance and operational troubleshooting. It is crucial for tracking user activity but does not automate compliance assessments or evidence collection.

Reference:

https://docs.aws.amazon.com/audit-manager/latest/userguide/what-is.html

-------------------

Amazon Inspector

Amazon Inspector is an automated security assessment service that helps improve the security and compliance of applications deployed on AWS. It automatically assesses applications for exposure, vulnerabilities, and deviations from best practices, making it an essential tool for ensuring the security of AI systems.

Incorrect options:

AWS Config - AWS Config is a service that enables you to assess, audit, and evaluate the configurations of your AWS resources. While it is important for governance and compliance monitoring, it does not perform automated security assessments of applications.

AWS Audit Manager - AWS Audit Manager helps you continuously audit your AWS usage to simplify how you assess risk and compliance with regulations and industry standards. It focuses on audit and compliance reporting rather than automated security assessments.

AWS Artifact - AWS Artifact provides on-demand access to AWS’ compliance reports and online agreements. It helps with compliance reporting but does not offer automated security assessments of applications.

Reference:

https://aws.amazon.com/inspector/features/